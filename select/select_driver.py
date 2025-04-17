"""
Driver code for selection of  K^{pm} from e^{+}e^{-} -> K^{+}K^{-} process

Developed by Daniel Ivanov (daniilivanov1606@gmail.com)
"""

import subprocess as sub
from multiprocessing.pool import Pool
import re

Phi2024 = [
    "root://cmd//scan2024_phi/scan2024_phi_tr_ph_fc_e500_0_v9.root",
    "root://cmd//scan2024_phi/scan2024_phi_tr_ph_fc_e501_0_v9.root",
    "root://cmd//scan2024_phi/scan2024_phi_tr_ph_fc_e503_0_v9.root",
    "root://cmd//scan2024_phi/scan2024_phi_tr_ph_fc_e505_0_v9.root",
    "root://cmd//scan2024_phi/scan2024_phi_tr_ph_fc_e506.5_0_v9.root",
    "root://cmd//scan2024_phi/scan2024_phi_tr_ph_fc_e508_0_v9.root",
    "root://cmd//scan2024_phi/scan2024_phi_tr_ph_fc_e508.5_0_v9.root",
    "root://cmd//scan2024_phi/scan2024_phi_tr_ph_fc_e509_0_v9.root",
    "root://cmd//scan2024_phi/scan2024_phi_tr_ph_fc_e509.5_0_v9.root",
    "root://cmd//scan2024_phi/scan2024_phi_tr_ph_fc_e510_0_v9.root",
    "root://cmd//scan2024_phi/scan2024_phi_tr_ph_fc_e510.5_0_v9.root",
    "root://cmd//scan2024_phi/scan2024_phi_tr_ph_fc_e511_0_v9.root",
    "root://cmd//scan2024_phi/scan2024_phi_tr_ph_fc_e511.5_0_v9.root",
    "root://cmd//scan2024_phi/scan2024_phi_tr_ph_fc_e512.5_0_v9.root",
    "root://cmd//scan2024_phi/scan2024_phi_tr_ph_fc_e512.5_1_0_v9.root",
    "root://cmd//scan2024_phi/scan2024_phi_tr_ph_fc_e515_0_v9.root",
    "root://cmd//scan2024_phi/scan2024_phi_tr_ph_fc_e520_0_v9.root",
]


Phi2018 = [
    "root://cmd//scan2018_omphi/scan2018_omphi_tr_ph_fc_e501_v9.root",
    "root://cmd//scan2018_omphi/scan2018_omphi_tr_ph_fc_e503_v9.root",
    "root://cmd//scan2018_omphi/scan2018_omphi_tr_ph_fc_e505_v9.root",
    "root://cmd//scan2018_omphi/scan2018_omphi_tr_ph_fc_e508.5_v9.root",
    "root://cmd//scan2018_omphi/scan2018_omphi_tr_ph_fc_e508_v9.root",
    "root://cmd//scan2018_omphi/scan2018_omphi_tr_ph_fc_e509.5_v9.root",
    "root://cmd//scan2018_omphi/scan2018_omphi_tr_ph_fc_e509_v9.root",
    "root://cmd//scan2018_omphi/scan2018_omphi_tr_ph_fc_e510.5_v9.root",
    "root://cmd//scan2018_omphi/scan2018_omphi_tr_ph_fc_e510_v9.root",
    "root://cmd//scan2018_omphi/scan2018_omphi_tr_ph_fc_e511.5_v9.root",
    "root://cmd//scan2018_omphi/scan2018_omphi_tr_ph_fc_e511_v9.root",
    "root://cmd//scan2018_omphi/scan2018_omphi_tr_ph_fc_e514_v9.root",
    "root://cmd//scan2018_omphi/scan2018_omphi_tr_ph_fc_e517_v9.root",
    "root://cmd//scan2018_omphi/scan2018_omphi_tr_ph_fc_e520_v9.root",
    "root://cmd//scan2018_omphi/scan2018_omphi_tr_ph_fc_e525_v9.root",
    "root://cmd//scan2018_omphi/scan2018_omphi_tr_ph_fc_e530_v9.root",
]


def prep_output(input: str) -> str:
    match = re.search(r"scan(\d+).*e(\d+\.?\d+)", input.split(r"/")[-1])
    if match:
        return f"kpkm_scan{match.group(1)}_e{match.group(2)}.root"
    else:
        return "error"


def execute_selection(input_file: str, output_name: str):
    aux1, aux2 = '"', "\\"
    command = f'root -l -q "select.cpp(\\{aux1 + "kpkmExp.cpp" + aux2}", \
                \\{aux1 + "kpkmExp" + aux2}",\
                \\{aux1 + input_file + aux2}", \
                \\{aux1 + output_name + aux2}")"'
    res = sub.run(command, capture_output=True, shell=True)
    output = res.stderr if res.stderr else res.stdout
    print(
        f"[{input_file} tr_ph processing exited with {res.returncode}]",
        flush=True,
    )
    print(output.decode()[118:], flush=True)


############# Driver code #############
if __name__ == "__main__":
    params = [(inp, prep_output(inp)) for inp in Phi2024]
    params += [(inp, prep_output(inp)) for inp in Phi2018]

    import time

    start = time.time()
    print(f"Number of tasks: {len(params)}")
    print("Selection started")
    with Pool(17) as pool:
        pool.starmap(execute_selection, params)
    end = time.time()
    print(f"exec time: {round(end - start, 3)} s or {round((end - start)/60, 2)} min")
