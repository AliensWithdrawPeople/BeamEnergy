from pathlib import Path
import sys

sys.path.append(str(Path(__file__).parent.parent))
print(str(Path(__file__).parent))
from secret import ROOT_FOLDER
