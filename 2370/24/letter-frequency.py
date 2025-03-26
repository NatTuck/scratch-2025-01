

def get(xs, key):
    for (k, v) in xs:
        if k == key:
            return v
    return 0

def put(xs, key, val):
    ys = []
    seen = False
    for (k, v) in xs:
        if k == key:
            v = val
            seen = True
        ys.append((k, v))
    if not seen:
        ys.append((key, val))
    return ys

counts = {}

with open("/usr/share/dict/words") as fh:
    for word in fh:
        word = word.strip()
        for letter in word:
            x = counts.get(letter, 0)
            counts[letter] = x + 1

print(counts)