from datetime import datetime
from eval import prepare_dataframe as prep
from eval.average import ultimate_averager as avg
from eval.utils import Season, make_a_point
from secret import ROOT_FOLDER

from pathlib import Path
import json
from datetime import datetime


root_folder = Path(ROOT_FOLDER)
results_path = Path(
    root_folder, f"results/result_{datetime.today().strftime("%d%m%Y")}.json"
)

phi2018 = Season(
    name="Phi2018",
    season_info=Path(root_folder, "tables/phi2018.csv"),
    graphs_location=Path(root_folder, "data/Phi2018/graphs"),
    tables_location=Path(root_folder, "data/Phi2018/hists"),
)

phi2024 = Season(
    name="Phi2024",
    season_info=Path(root_folder, "tables/phi2024.csv"),
    graphs_location=Path(root_folder, "data/Phi2024/graphs"),
    tables_location=Path(root_folder, "data/Phi2024/hists"),
)

if __name__ == "__main__":
    points = make_a_point(phi2018)
    points.extend(make_a_point(phi2024))

    results = {}
    for point in points:
        df = prep.retrieve_raw_table(point)
        df = prep.add_energies(point, df)
        results[f"scan{point.season.name}_e{point.name}"] = avg(df)
    with open(results_path) as file:
        json.dump(results, file, indent=4)
