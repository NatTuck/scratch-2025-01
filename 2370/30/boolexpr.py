import re


class BoolExpr:
    def simplify(self):
        # FIXME: This should do stuff.
        return self


class Var(BoolExpr):
    def __init__(self, name):
        self.name = name

    def __eq__(self, other):
        return other is Var and self.name == other.name

    def __repr__(self):
        return self.name


class Lit(BoolExpr):
    def __init__(self, val):
        self.val = val

    def __eq__(self, other):
        return other is Lit and self.val == other.val

    def __repr__(self):
        return self.val


class Not(BoolExpr):
    def __init__(self, expr):
        self.expr = expr

    def __eq__(self, other):
        return other is Not and self.expr == other.expr

    def __repr__(self):
        return f"!{self.expr}"


class And(BoolExpr):
    def __init__(self, exprs):
        self.exprs = exprs

    def __eq__(self, other):
        return other is And and self.exprs == other.exprs

    def __repr__(self):
        text = "".join(map(str, self.exprs))
        return f"({text})"


class Or(BoolExpr):
    def __init__(self, exprs):
        self.exprs = exprs

    def __eq__(self, other):
        return other is Or and self.exprs == other.exprs

    def __repr__(self):
        text = "+".join(map(str, self.exprs))
        return f"({text})"


def next_group(text):
    count = 1
    for ii in range(1, len(text)):
        if text[ii] == "(":
            count += 1
        if text[ii] == ")":
            count -= 1
        if count == 0:
            return text[1:ii]
    raise Exception("mismatched parens")


def parse_one(text):
    """Parse one literal, var, not, or parens."""
    text = text.lstrip()

    if mm := re.match(r"[01]", text):
        return (Lit(mm[0]), text[1:])

    if mm := re.match(r"[A-Za-z]", text):
        return (Var(mm[0]), text[1:])

    if mm := re.match(r"[!]", text):
        (arg, rest) = parse_one(text[1:])
        if arg:
            print(f"not arg: {arg} ({rest})")
            return (Not(arg), rest)
        else:
            raise Exception("no arg for not")

    if mm := re.match(r"\(", text):
        group = next_group(text)
        return (parse(group), text[len(group) + 2 :])

    return None


def parse_and(text):
    """Get one AND group."""
    ys = []

    while pair := parse_one(text):
        (item, text) = pair

        ys.append(item)

    if len(ys) == 0:
        return None

    if len(ys) == 1:
        return (ys[0], text)

    return (And(ys), text)


def parse(text):
    """Parse a full expression."""

    ys = []

    while pair := parse_and(text):
        (item, text) = pair
        text = text.lstrip()

        if len(text) == 0:
            ys.append(item)
            break

        if text[0] == "+":
            ys.append(item)
            text = text[1:]
        else:
            raise Exception("excess characters: " + text)

    if len(ys) == 0:
        raise Exception("empty expr")

    if len(ys) == 1:
        return ys[0]

    return Or(ys)


def test_parse():
    assert str(parse("1")) == "1"
    assert str(parse("a")) == "a"
    assert str(parse("!a")) == "!a"
    assert str(parse("ab")) == "(ab)"
    assert str(parse("a+b+c")) == "(a+b+c)"
