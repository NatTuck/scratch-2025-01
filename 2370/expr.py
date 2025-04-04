
import re

class Expr:
    def eval(self, bindings):
        raise Exception("Not implemented")


class Lit(Expr):
    def __init__(self, val):
        self.val = val

    def eval(self, bindings):
        return self.val

    def __eq__(self, other):
        return type(self) == type(other) and self.val == other.val

def test_Lit():
    t = Lit(True)
    assert t.eval({}) == True
    f = Lit(False)
    assert f.eval({}) == False


class Var(Expr):
    def __init__(self, name):
        self.name = name

    def eval(self, bindings):
        return bindings[self.name]
    
    def __eq__(self, other):
        return type(self) == type(other) and self.name == other.name

def test_Var():
    bindings = {"a": True, "b": False, "c": True}
    assert Var("a").eval(bindings) == True
    assert Var("b").eval(bindings) == False
    assert Var("c").eval(bindings) == True


class And(Expr):
    def __init__(self, exprs):
        self.exprs = exprs

    def eval(self, bindings):
        for expr in self.exprs:
            if not expr.eval(bindings):
                return False
        return True

def test_And():
    t = Lit(True)
    f = Lit(False)
    a = Var("a")
    b = Var("b")
    bindings = {"a": True, "b": False, "c": True}
    assert And([f, f]).eval(bindings) == False
    assert And([b, t]).eval(bindings) == False
    assert And([t, t, a]).eval(bindings) == True


class Or(Expr):
    def __init__(self, exprs):
        self.exprs = exprs

    def eval(self, bindings):
        for expr in self.exprs:
            if expr.eval(bindings):
                return True
        return False


class Not(Expr):
    def __init__(self, expr):
        self.expr = expr

    def eval(self, bindings):
        return not self.expr.eval(bindings)


def parse(text: str) -> Expr:
    for cc in text:
        if cc == '0':
            return Lit(False)
        if cc == '1':
            return Lit(True)
        if re.match(r"[A-Za-z]", cc):
            return Var(cc)
    

def test_parse():
    assert parse("0") == Lit(False)
    assert parse("1") == Lit(True)
    assert parse("a") == Var("a")
    assert parse("b") == Var("a")
    assert parse("bc") == And([Var("b"), Var("c")])

# abc + a!bc + ((a + b)(!a + !b))
# ee = Or(And([Var('a'), Var('b'), Var('c')]), And([Var('a', Not(Var('b')), Var('c')]))



