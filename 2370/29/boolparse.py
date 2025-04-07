
import re

class Var:
    def __init__(self, name):
        self.name = name

    def __eq__(self, other):
        return self.name == other.name

    def __repr__(self):
        return f"Var({self.name})"

class Lit:
    def __init__(self, val):
        self.val = val

    def __eq__(self, other):
        return self.val == other.val

    def __repr__(self):
        return f"Lit({self.val})"


class Not:
    def __init__(self, expr):
        self.expr = expr
    
    def __eq__(self, other):
        return self.expr == other.expr

    def __repr__(self):
        return f"!({self.expr})"


class And:
    def __init__(self, exprs):
        self.exprs = exprs
    
    def __eq__(self, other):
        return self.exprs == other.exprs

    def __repr__(self):
        return f"And({self.exprs})"

class Or:
    def __init__(self, exprs):
        self.exprs = exprs
    
    def __eq__(self, other):
        return self.exprs == other.exprs

    def __repr__(self):
        return f"Or({self.exprs})"


def parse_vand(text):
    """Text matches r'^[A-Za-z!]+[A-Za-z]$', get an And([...])"""
    
    if text[0] == '!':
        # Start with !var
        first = Not(Var(text[1]))
        if len(text) == 1:
            return first
        else:
            return And([first, parse_vand(text[2:])])
    else:
        # Start with var
        first = Var(text[0])
        if len(text) == 2:
            return first
        else:
            rest = parse_vand(text[1:])
            return And([first, rest])



def parse_vand_test():
    assert parse_vand("x") == Var("x")
    assert parse_vand("!x") == Not(Var("x"))
    assert parse_vand("xy") == And([Var("x"), Var("y")])
    assert parse_vand("!xy") == And([Not(Var("x")), Var("y")])
    assert parse_vand("x!y") == And([Var("x"), Not(Var("y"))])
    

def parse(text):
    """ab+bc"""
    if match := re.match(r'^[01]$', text):
        return Lit(match[0])

    if match := re.match(r'^(.+)\+(.+)$', text):
        left = parse(match[1])
        right = parse(match[2])
        return Or([left, right])

    if match := re.match(r'^[A-Za-z!]+[A-Za-z]$', text):
        mt = match[0]
           
        if mt[0] == "!":
            Not(Var(mt[1]))
        xs = []
        for vv in mt:
            xs.append(Var(vv))
        return And(xs)

    if match := re.match(r'^!$', text):
        operand = parse(text[1:])
        return Not(operand)
   
    if match := re.match(r'^[A-Za-z]$', text):
        return Var(match[0])
    


def test_parse():
    assert parse("1") == Lit("1")
    assert parse("a") == Var("a")
    assert parse("!a") == Not(Var("a"))
    assert parse("ab") == And([Var("a"), Var("b")])

print("1 =>", parse("1"))
print("a =>", parse("a"))
print("!a =>", parse("!a"))
print("ab =>", parse("ab"))
print("a+b =>", parse("a+b"))
print("ab+bc =>", parse("ab+bc"))
print("a!b+!bc =>", parse("a!b+!bc"))


