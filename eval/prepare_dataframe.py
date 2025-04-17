"""
Prepares a dataframe for an energy averaging.
The output dataframe has columns:
* `e_mean` (mean energy of the group of a run)
* `e_std` (error of the mean energy)
* `luminosity` (luminosity of a run)

Developed by Daniel Ivanov (daniilivanov1606@gmail.com)
"""

from utils import Point
import pandas as pd
import uproot as up
import numpy as np


def retrieve_raw_table(point: Point) -> pd.DataFrame:
    """
    Load  compton energy tables.
    If several tables found for the same energy point,
    the one with highest starting run num is taken.
    """
    df = pd.read_csv(point.table_location)
    return df


def add_energies(point: Point, df: pd.DataFrame) -> pd.DataFrame:
    """Add charged K energy measurement data.
    In particular, adds columns:
    * 'e_mean'
    * 'e_std'
    """
    with up.open(point.graph_location) as file:  # type: ignore
        bcs = file["grKchEnergy"]
    run: np.ndarray = np.array(bcs.member("fX"))  # type: ignore
    energies: np.ndarray = np.array(bcs.member("fY"))  # type: ignore
    energy_errors: np.ndarray = np.array(bcs.member("fEY"))  # type: ignore
    df["e_mean"] = energies
    df["e_std"] = energy_errors
    return df
