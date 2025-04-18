import vector
import uproot as up
from pathlib import Path
import pandas as pd
import numpy as np


def eval_boost(input: Path, output: Path) -> pd.DataFrame:
    aliases = {"energy": "emeas", "mom": "tptotv", "theta": "tthv", "phi": "tphiv"}
    branches = ["energy", "mom", "theta", "phi"]
    with up.open(f"{input.as_posix()}:kChargedTree") as tree:  # type: ignore
        df: pd.DataFrame = tree.arrays(branches, aliases=aliases, library="pd")

    for branch in ["mom", "theta", "phi"]:
        df[f"{branch}_K_pos"] = df[branch].apply(lambda x: x[0])
        df[f"{branch}_K_neg"] = df[branch].apply(lambda x: x[1])

    df["pt_K_pos"] = df[["mom_K_pos", "theta_K_pos"]].apply(
        lambda x: x["mom_K_pos"] * np.sin(x["theta_K_pos"]), axis="columns"
    )
    df["pt_K_neg"] = df[["mom_K_neg", "theta_K_neg"]].apply(
        lambda x: x["mom_K_neg"] * np.sin(x["theta_K_neg"]), axis="columns"
    )
    df["Mass"] = [493.677] * len(df)
    arr_pos = vector.array(
        {
            "pt": df["pt_K_pos"],
            "phi": df["phi_K_pos"],
            "theta": df["theta_K_pos"],
            "tau": df["Mass"],
        }
    )
    arr_neg = vector.array(
        {
            "pt": df["pt_K_neg"],
            "phi": df["phi_K_neg"],
            "theta": df["theta_K_neg"],
            "tau": df["Mass"],
        }
    )

    sum = arr_neg.add(arr_pos)
    df["tot_pz"] = sum.to_ptphipz().z

    with up.recreate(output) as new_file:
        new_file["boost"] = df
    print("Total pz mean =", df["tot_pz"].mean())
    print("Total pz std =", df["tot_pz"].std() ** 0.5)
    print(f"Output tree `boost` is saved in {output}")
    return df
