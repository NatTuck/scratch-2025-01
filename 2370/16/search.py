
from pathlib import Path

"""
Find all files named with a .py extension
anywhere under the current directory.
"""

def find_all(path: Path, ext: str) -> list[str]:
    
    files = []
    
    for child in path.iterdir():
        if child.is_dir():
            files += find_all(child, ext)
        elif str(child).endswith(ext):
            files.append(str(child))

    return files


if __name__ == '__main__':
    wd = Path.cwd()
    print(len(find_all(wd, '.py')))