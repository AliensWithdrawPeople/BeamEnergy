from datetime import datetime
from eval import prepare_dataframe as prep
from eval.average import ultimate_averager as avg
from eval.utils import Season, make_a_point
from secret import ROOT_FOLDER

from pathlib import Path
import json
from datetime import datetime
from tqdm import tqdm

root_folder = Path(ROOT_FOLDER)
results_path = Path(
    root_folder, f"results/result_{datetime.today().strftime("%d%m%Y")}.json"
)

phi2018 = Season(
    name="Phi2018",
    season_info=Path(root_folder, "tables/phi2018.csv"),
    graphs_location=Path(root_folder, "results/Phi2018/graphs"),
    compton_tables=Path(root_folder, "tables/Compton/energy_points/RHO2018"),
    output_tables=Path(root_folder, "tables/k_charged/RHO2018"),
)

phi2024 = Season(
    name="Phi2024",
    season_info=Path(root_folder, "tables/phi2024.csv"),
    graphs_location=Path(root_folder, "results/Phi2024/graphs"),
    compton_tables=Path(root_folder, "tables/Compton/energy_points/PHI2024"),
    output_tables=Path(root_folder, "tables/k_charged/PHI2024"),
)

if __name__ == "__main__":
    points2018 = make_a_point(phi2018)
    points2024 = make_a_point(phi2024)
    points_dict = {"Phi2018": points2018, "Phi2024": points2024}
    for set_name, points in points_dict.items():
        results = {}
        print(f"Processing {set_name}...")
        for point in tqdm(points):
            df = prep.retrieve_raw_table(point)
            df = prep.add_energies(point, df)
            df.to_csv(point.output_table, na_rep="None", index=False)
            results[f"{point.season.name}_e{point.name}"] = avg(df.dropna())
            results[f"{point.season.name}_e{point.name}"] = avg(
                df.dropna(), e_mean_key="delta_e"
            )
        _results_path = results_path.with_stem(
            results_path.stem.replace("result", f"results_{set_name}_delta_E")
        )
        results = {
            k: results[k]
            for k in sorted(results, key=lambda x: float(x.split("_e")[1]))
        }
        with open(_results_path, "w+") as file:
            json.dump(results, file, indent=4)
