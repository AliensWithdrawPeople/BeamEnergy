import matplotlib.pyplot as plt
from plothist import make_hist, plot_hist
from pathlib import Path
import pandas as pd

from utils import ROOT_FOLDER

result_phi2018 = Path(ROOT_FOLDER, "tables/k_charged/RHO2018/Phi2018_e508.5.csv")
result_phi2024 = Path(ROOT_FOLDER, "tables/k_charged/PHI2024/Phi2024_e508.5.csv")
output = Path(ROOT_FOLDER, "results/delta_E_comparison_508.5_MeV.svg")
n_bins = 28

df_2018 = pd.read_csv(result_phi2018).dropna()
df_2024 = pd.read_csv(result_phi2024).dropna()

variable = "delta_e"
x2018 = df_2018[variable][df_2018["accepted"] == 1]
x2024 = df_2024[variable][df_2024["accepted"] == 1]
print(max(*x2024))
x_range = (min(*x2018, *x2024) * 0.98, max(*x2018, *x2024) * 1.02)
bin_width = round((x_range[1] - x_range[0]) / n_bins, 2)
# x_range = (3.5, 4.5)
h2018 = make_hist(x2018, bins=n_bins, range=x_range)
h2024 = make_hist(x2024, bins=n_bins, range=x_range)

fig, ax = plt.subplots()

plot_hist(h2018, ax=ax, histtype="step", linewidth=1.2, label="PHI2018")
plot_hist(h2024, ax=ax, histtype="step", linewidth=1.2, label="PHI2024")

ax.set_xlabel(r"\Delta E, MeV")
ax.set_ylabel(f"Entries/{bin_width} MeV")
ax.set_xlim(x_range)
ax.legend()

fig.savefig(output, bbox_inches="tight")  # type: ignore
print(f"Output file saved: {output}")
