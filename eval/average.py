"""
Script to average energy.

Developed by Nikita Petrov (source: https://cmd.inp.nsk.su/~compton/gogs/compton/sources)
Tailored by Daniel Ivanov (daniilivanov1606@gmail.com)
"""

from iminuit import Minuit
import numpy as np
import pandas as pd


class Likelihood:
    """
    Likelihood function
    """

    def __init__(self, means: np.ndarray, sigmas: np.ndarray, weights: np.ndarray):
        """
        Parameters
        ----------
        means : np.array
            array of means, [MeV]
        sigmas : np.array
            array of standard deviations, [MeV]
        weights : np.array
            array of luminosities
        """

        self.means = means
        self.sigmas = sigmas
        self.weights = weights / weights.mean()
        # w_norm = (weights**2).sum()/(weights.sum())
        # self.weights = weights/w_norm

    def __call__(self, mean: float, sigma: float):
        """
        Calls likelihood calculation

        Parameters
        ----------
        mean : float
            expected mean
        sigma : float
            expected standard deviation
        """

        sigma_total = np.sqrt(sigma**2 + self.sigmas**2)
        ln_L = -np.sum(
            self.weights
            * (
                ((mean - self.means) ** 2) / (2 * (sigma_total**2))
                + np.log(sigma_total)
            )
        )
        return -ln_L


def __estimate_point_with_closest(
    comb_df: pd.DataFrame, runs_df: pd.DataFrame, compton_df: pd.DataFrame
):
    # estimate energy by the nearest points
    min_run_time = (
        runs_df[runs_df.run == comb_df.iloc[0].at["run_first"]].iloc[0].at["starttime"]
    )
    max_run_time = (
        runs_df[runs_df.run == comb_df.iloc[0].at["run_last"]].iloc[0].at["stoptime"]
    )

    nearest_row_before = compton_df.iloc[
        pd.Index(compton_df.endtime).get_loc(min_run_time, "nearest")
    ]
    nearest_row_after = compton_df.iloc[
        pd.Index(compton_df.begintime).get_loc(max_run_time, "nearest")
    ]

    # regulatization
    nearest_row_before["data"][1] = max(nearest_row_before["data"][3], 1e-3)
    nearest_row_after["data"][3] = max(nearest_row_after["data"][3], 1e-3)
    nearest_row_before["data"][1] = max(nearest_row_before["data"][1], 1e-3)
    nearest_row_after["data"][3] = max(nearest_row_after["data"][3], 1e-3)

    mean_energy = (nearest_row_before["data"][0] + nearest_row_after["data"][0]) / 2
    mean_spread = (nearest_row_before["data"][2] + nearest_row_after["data"][2]) / 2
    std_energy = np.sqrt(
        1
        / (
            1 / (nearest_row_before["data"][1]) ** 2
            + 1 / (nearest_row_after["data"][1]) ** 2
        )
    )
    std_spread = np.sqrt(
        1
        / (
            1 / (nearest_row_before["data"][3]) ** 2
            + 1 / (nearest_row_after["data"][3]) ** 2
        )
    )
    sys_energy = np.std([nearest_row_before["data"][0], nearest_row_after["data"][0]])

    return {
        "energy_point": comb_df.elabel.min(),
        "first_run": comb_df.run_first.min(),
        "last_run": comb_df.run_last.max(),
        "mean_energy": mean_energy,
        "mean_energy_stat_err": std_energy,
        "mean_energy_sys_err": sys_energy,
        "mean_spread": mean_spread,
        "mean_spread_stat_err": std_spread,
        "used_lum": 0,
        "comment": "indirect measurement #2",
    }, pd.DataFrame([])


def ultimate_averager(
    df: pd.DataFrame, e_mean_key: str = "e_mean", e_std_key: str = "e_std"
) -> dict:
    """Complete averager for estimation of mean energy and energy spread

    Parameters
    ----------
    df : pd.DataFrame
        input dataframe containing means and spreads

    Returns
    -------
    dict
        averaged mean and spread
    """

    m = Minuit(
        Likelihood(df[e_mean_key], df[e_std_key], df["luminosity"]),  # type: ignore
        mean=df[e_mean_key].mean(),
        sigma=df[e_mean_key].std(ddof=0),
    )
    m.errordef = 0.5
    m.limits["sigma"] = (0, None)
    m.migrad()
    m.hesse()
    sys_err = m.values["sigma"]
    mean_en = m.values["mean"]

    mean_spread = np.sum(
        df.spread_mean * df.luminosity / (df.spread_std**2)
    ) / np.sum(df.luminosity / (df.spread_std**2))
    std_spread = np.sqrt(
        1 / np.sum((df.luminosity / df.luminosity.mean()) / df.spread_std**2)
    )
    return {
        "mean_energy": mean_en,
        "mean_energy_stat_err": round(m.errors["mean"], 5),
        "mean_energy_sys_err": round(sys_err, 5),
        "mean_spread": mean_spread,
        "mean_spread_stat_err": round(std_spread, 5),
    }
