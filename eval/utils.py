"""
Utilities for the analysis.

Developed by Daniel Ivanov (daniilivanov1606@gmail.com)
"""

import csv
from dataclasses import dataclass, field
from pathlib import Path
import warnings


@dataclass
class Season:
    name: str
    season_info: Path
    graphs_location: Path
    compton_tables: Path
    output_tables: Path


def _make_graph_filename(point) -> str:
    return f"graph_scan{point.season.name[-4:]}_e{point.name}.root"


@dataclass
class Point:
    season: Season
    name: str
    compton_mean: float
    graph_location: Path = field(init=False)
    compton_table: Path = field(init=False)
    output_table: Path = field(init=False)

    def __post_init__(self):
        self.graph_location = Path(
            self.season.graphs_location, _make_graph_filename(self)
        )
        if not self.graph_location.exists():
            raise RuntimeError(
                f"There is no {self.graph_location} file for {self.name} from season {self.season.name}."
            )

        table = [
            table
            for table in self.season.compton_tables.iterdir()
            if float(table.stem.split("_")[0]) == float(self.name)
        ]
        if not table:
            raise RuntimeError(
                f"Can't load raw table for energy point {self.name} from season {self.season.name}"
            )
        if len(table) > 1:
            warnings.warn(
                f"There are {len(table)} table for {self.name} from season {self.season.name} found.\
                Expected 1. The one with the largest run number is taken.",
                category=RuntimeWarning,
            )
            table.sort(key=lambda path: int(path.stem.split("_")[1]), reverse=True)
        self.compton_table = table[0]

        self.output_table = Path(
            self.season.output_tables, f"{self.season.name}_e{self.name}.csv"
        )


def make_a_point(season: Season) -> list[Point]:
    """Read [this](https://www.alexandrafranzen.com/2016/03/29/how-to-make-your-point/) to understand."""
    with open(season.season_info) as csvfile:
        reader = csv.DictReader(csvfile)
        points = [
            Point(
                season=season,
                name=row["energy_point"],
                compton_mean=float(row["mean_energy"]),
            )
            for row in reader
            if 501 < float(row["energy_point"]) < 532 and int(row["first_run"]) > 59000
        ]
    return points
