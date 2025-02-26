
from pathlib import Path

wd = Path.cwd()
parent = wd / ".."

for item in parent.iterdir():
    print(item)