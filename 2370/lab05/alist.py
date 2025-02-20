
def empty_alist():
    return []


def get_alist(xs, key):
    for pair in xs:
        (kk, vv) = pair
        if kk == key:
            return vv
    print(xs)
    raise Exception("No such key: " + key)
    

def test_get_alist():
    xs = [("cow", "moo"), ("dog", "bark")]
    assert get_alist(xs, "cow") == "moo"


def put_alist2(xs, key, val):
    ys = []
    for pair in xs:
        (kk, vv) = pair:w
        if not key == kk:
            ys.append(pair)
    ys.append((key, val))
    return ys


def alist_has_key(xs, key):
    for pair in xs:
        (kk, vv) = pair
        if key == kk:
            return True
    return False


def put_alist(xs, key, val):
    ys = []
    if alist_has_key(xs, key):
        for x in xs:
            (kk, vv) = x
            if kk == key:
                ys.append((kk, vv))
            else:
                ys.append(x)
    else:
        for x in xs:
            ys.append(x)
        ys.append((key, val))
    return ys

def test_put_alist():
    xs = []
    xs = put_alist(xs, "goat", "baa")
    assert get_alist(xs, "goat") == "baa"
    xs = put_alist(xs, "goat", "moo")
    assert get_alist(xs, "goat") == "moo"
    xs = put_alist(xs, "dog", "bark")
    assert get_alist(xs, "goat") == "moo"
    assert get_alist(xs, "dog") == "bark"
    
    
    



