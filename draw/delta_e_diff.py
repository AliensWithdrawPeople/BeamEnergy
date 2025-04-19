import json
from pathlib import Path
import re
import matplotlib.pyplot as plt
from scipy.interpolate import Akima1DInterpolator

from utils import ROOT_FOLDER

output = Path(ROOT_FOLDER, "results/delta_E_diff.svg")
energy_fit_results_phi2018 = Path(ROOT_FOLDER, "results/results_Phi2018_18042025.json")
fit_results_phi2024 = Path(ROOT_FOLDER, "results/results_Phi2024_18042025.json")

delta_E_fit_results_phi2018 = Path(
    ROOT_FOLDER, "results/results_Phi2018_delta_E_18042025.json"
)
delta_E_fit_results_phi2024 = Path(
    ROOT_FOLDER, "results/results_Phi2024_delta_E_18042025.json"
)

phi2018: dict = json.loads(energy_fit_results_phi2018.read_text())
delta_E_phi2018: dict = json.loads(delta_E_fit_results_phi2018.read_text())
phi2024: dict = json.loads(fit_results_phi2024.read_text())
delta_E_phi2024: dict = json.loads(delta_E_fit_results_phi2024.read_text())

x = []
deltaE_diff = []
deltaE_diff_err = []

delta_E_2018 = []
delta_E_error_2018 = []
e_2018 = []

for point, fit_info in phi2018.items():
    if fit_info["mean_energy_stat_err"] > 0.1 or fit_info["mean_energy_sys_err"] > 0.1:
        continue
    e_2018.append(fit_info["mean_energy"])
    delta_E_2018.append(delta_E_phi2018[point]["mean_energy"])
    delta_E_error_2018.append(
        (
            delta_E_phi2018[point]["mean_energy_stat_err"] ** 2
            + delta_E_phi2018[point]["mean_energy_sys_err"] ** 2
        )
        ** 0.5
    )
delta_E_2018_interp = Akima1DInterpolator(e_2018, delta_E_2018)


def extract_energy(point_name: str) -> str | None:
    match = re.search(r"e(\d+.?\d+)", point_name)
    if match:
        return match.group(1)
    return None


for point, fit_info in phi2024.items():
    energy = extract_energy(point)

    if energy is None or float(energy) < 505:
        continue
    x.append(energy)

    deltaE_diff.append(
        delta_E_phi2024[point]["mean_energy"]
        - delta_E_2018_interp(fit_info["mean_energy"])
    )
    error = (
        fit_info["mean_energy_stat_err"] ** 2 + fit_info["mean_energy_sys_err"] ** 2
    ) ** 0.5
    deltaE_diff_err.append(error)

fig, ax = plt.subplots()
ax.errorbar(x, deltaE_diff, yerr=deltaE_diff_err, fmt="o")

ax.set_xlabel(r"Phi2024 Energy point")
ax.set_ylabel(r"2024-2018 diff, MeV")

fig.savefig(output, bbox_inches="tight")  # type: ignore
print(f"Output file saved: {output}")
