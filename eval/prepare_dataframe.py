"""
Prepares a dataframe for an energy averaging.
The output dataframe has columns:
* `e_mean` (mean energy of the group of a run)
* `e_std` (error of the mean energy)
* `luminosity` (luminosity of a run)

Developed by Daniel Ivanov (daniilivanov1606@gmail.com)
"""

from .utils import Point
import pandas as pd
import uproot as up
import numpy as np


def retrieve_raw_table(point: Point) -> pd.DataFrame:
    """
    Load  compton energy tables.
    If several tables found for the same energy point,
    the one with highest starting run num is taken.
    """
    df = pd.read_csv(point.compton_table)
    return df


def add_energies(point: Point, df: pd.DataFrame) -> pd.DataFrame:
    """Add charged K energy measurement data.
    In particular, adds columns:
    * 'e_mean'
    * 'e_std'
    """
    with up.open(point.graph_location) as file:  # type: ignore
        bcs = file["grKchEnergy"]
    runs: np.ndarray = np.array(bcs.member("fX"))  # type: ignore
    energies: np.ndarray = np.array(bcs.member("fY"))  # type: ignore
    energy_errors: np.ndarray = np.array(bcs.member("fEY"))  # type: ignore

    df["e_mean_compton"] = df["e_mean"]
    df["e_std_compton"] = df["e_std"]

    df["e_mean"] = [np.nan] * len(df)
    df["e_std"] = [np.nan] * len(df)
    df["delta_e"] = [np.nan] * len(df)

    for run, energy, energy_err in zip(runs, energies, energy_errors):
        energy, energy_err = round(energy, 4), round(energy_err, 4)
        mask: pd.Series = (df["run_first"] <= run) & (run <= df["run_last"])
        if energy == 0 or energy_err == 0:
            energy, energy_err = np.nan, np.nan
        df.loc[mask, ["e_mean", "e_std"]] = [energy, energy_err]
        df.loc[mask, "delta_e"] = round(df.loc[mask, "e_mean_compton"] - energy, 4)
    return df
