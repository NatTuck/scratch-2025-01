import re


class BoolExpr:
    def to_sop(self):
        return self

    def apply_not(self):
        return Not(self)

    def simplify(self):
        return self.eliminate_literals()

    def eliminate_literals(self):
        return self


class Var(BoolExpr):
    def __init__(self, name):
        self.name = name

    def __eq__(self, other):
        return type(other) is Var and self.name == other.name

    def __repr__(self):
        return self.name


class Lit(BoolExpr):
    def __init__(self, val):
        self.val = val

    def __eq__(self, other):
        return type(other) is Lit and self.val == other.val

    def __repr__(self):
        return self.val


class Not(BoolExpr):
    def __init__(self, expr):
        self.expr = expr

    def __eq__(self, other):
        return type(other) is Not and self.expr == other.expr

    def __repr__(self):
        return f"!{self.expr}"

    def apply_not(self):
        return self.expr
    
    def to_sop(self):
        expr = self.expr.eliminate_literals()
        if type(expr) is And or type(expr) is Or:
            return self.de_morgan().to_sop()
        else:
            return Not(expr.to_sop())

    def de_morgan(self):
        def apply_not(ex: BoolExpr) -> BoolExpr:
            return ex.apply_not()

        if type(self.expr) is And: 
            return Or(list(map(apply_not, self.expr.exprs)))
        if type(self.expr) is Or:
            return And(list(map(apply_not, self.expr.exprs)))
        return self

    def eliminate_literals(self):
        expr1 = self.expr.eliminate_literals()

        if expr1 == Lit("0"):
            return Lit("1")

        if expr1 == Lit("1"):
            return Lit("0")

        return Not(expr1)


class And(BoolExpr):
    def __init__(self, exprs):
        self.exprs = exprs

    def __eq__(self, other):
        return type(other) is And and self.exprs == other.exprs

    def __repr__(self):
        text = "".join(map(str, self.exprs))
        return f"({text})"
 
    def to_sop(self):
        for expr in self.exprs:
            if type(expr) is Or:
                rest = filter(lambda x: x == expr, self.exprs)
                return Or([And(a, b) for a in rest, be in expr.exprs ])

    
    def eliminate_literals(self):
        ys = []

        for expr in self.exprs:
            expr = expr.eliminate_literals()
            if type(expr) is Lit:
                if expr.val == '0':
                    return Lit('0')
                # Skip any Lit('1')
            else:
                ys.append(expr)

        if len(ys) == 0:
            return Lit("1")

        return And(ys)



class Or(BoolExpr):
    def __init__(self, exprs):
        self.exprs = exprs

    def __eq__(self, other):
        return type(other) is Or and self.exprs == other.exprs

    def __repr__(self):
        text = "+".join(map(str, self.exprs))
        return f"({text})"

    def eliminate_literals(self):
        ys = []

        for expr in self.exprs:
            expr = expr.eliminate_literals()
            if type(expr) is Lit:
                if expr.val == '1':
                    return Lit('1')
                # skip any Lit('0')
            else: 
                ys.append(expr)

        return Or(ys)

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
            #print(f"not arg: {arg} ({rest})")
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
