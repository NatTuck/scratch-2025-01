
import re

pat = re.compile("[^a-z’]")

def words_from(path: str) -> set[str]:
    words = set()
    with open(path) as fh:
        for line in fh:
            ws = set(re.split(pat, line.lower()))
            if 'o' in ws:
                print(line)
            words |= ws
    return words

xs = words_from("kjb.txt")
ys = words_from("plost.txt")

print("kjb:", len(xs))
print("plost:", len(ys))

shared = set()

for x in xs:
    if (x in ys) and (x not in shared):
        shared.add(x)

print("shared:", len(shared))
for w in shared:
    print(w)
