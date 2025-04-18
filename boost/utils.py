from pathlib import Path
import matplotlib.pyplot as plt
from plothist import make_hist, plot_hist

import sys

sys.path.append(str(Path(__file__).parent.parent))
from secret import ROOT_FOLDER


def hist(data, n_bins: int, pz_range: tuple[float, float], plot_output: Path):
    fig, ax = plt.subplots()
    h = make_hist(data, bins=n_bins, range=pz_range)
    bin_width = round(abs(pz_range[1] - pz_range[0]) / n_bins, 3)

    plot_hist(h, ax=ax)

    ax.set_xlabel(r"Total p_{z}, MeV")
    ax.set_ylabel(f"Entries/{bin_width} MeV")

    fig.savefig(plot_output, bbox_inches="tight")  # type: ignore
    print(f"Output file saved: {plot_output}")
