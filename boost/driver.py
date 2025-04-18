from pathlib import Path

from utils import ROOT_FOLDER, hist
from processing import eval_boost
import time

season_name = "Phi2024"
energy_name = "509"

key = f"scan{season_name[-4:]}_e{energy_name}"
input = Path(ROOT_FOLDER, f"data/{season_name}/kpkm_{key}.root")
output = Path(ROOT_FOLDER, f"boost/data/boost_{key}.root")
plot_output = Path(ROOT_FOLDER, f"boost/plots/total_pz_{key}.svg")

n_bins = 1000
pz_range = (-20, 20)  # MeV

start = time.time()
df = eval_boost(input, output)
hist(df["tot_pz"], n_bins, pz_range, plot_output)
end = time.time()
print(f"Execution took: {round(end - start, 2)} s or {round((end - start)/60, 2)} m")
