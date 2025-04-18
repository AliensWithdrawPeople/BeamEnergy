import json
from pathlib import Path
import re
import matplotlib.pyplot as plt
from plothist import make_hist, plot_hist

from utils import ROOT_FOLDER

output = Path(ROOT_FOLDER, "results/delta_E_diff.svg")
fit_results_phi2018 = Path(ROOT_FOLDER, "results/results_Phi2018_delta_E_18042025.json")
fit_results_phi2024 = Path(ROOT_FOLDER, "results/results_Phi2024_delta_E_18042025.json")

phi2018: dict = json.loads(fit_results_phi2018.read_text())
phi2024: dict = json.loads(fit_results_phi2024.read_text())

x = []
deltaE_diff = []


def extract_energy(point_name: str) -> str | None:
    match = re.search(r"e(\d+.?\d+)", point_name)
    if match:
        return match.group(1)
    return None


for point, fit_info in phi2018.items():
    energy = extract_energy(point)

    phi2024_point = phi2024.get(point.replace("2018", "2024"))
    if energy is None or phi2024_point is None or float(energy) < 505:
        continue
    x.append(energy)

    deltaE_diff.append(fit_info["mean_energy"] - phi2024_point["mean_energy"])
    if abs(deltaE_diff[-1]) > 1:
        print(x[-1])


fig, ax = plt.subplots()
ax.scatter(x, deltaE_diff)
# h = make_hist(deltaE_diff)

# plot_hist(h, ax=ax)

ax.set_xlabel(r"Energy point")
ax.set_ylabel(r"2018-2024 diff, MeV")

fig.savefig(output, bbox_inches="tight")  # type: ignore
print(f"Output file saved: {output}")
