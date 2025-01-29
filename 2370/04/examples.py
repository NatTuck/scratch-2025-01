
# Simple data:
#  - data that can't really be broken down
#    into smaller pieces
#  - examples: int, float, bool
#  - sometimes str, if we're not looking at
#    the individual characters much

from pytest import approx

# Design a function that adds 10 to a number.

def add10(xx: float) -> float:
    """Add 10 to a number."""
    return xx + 10

def test_add10():
    assert add10(10.0) == approx(20.0)
    assert add10(5.0) == approx(15.0)
    
# Design a function that takes a string
# and pluralizes it by sticking an "s" on
# end.

def pluralize(word: str) -> str:
    """Pluralize a string."""
    return word + "s"
    
def test_pluralize():
    assert pluralize("plant") == "plants"
    assert pluralize("dog") == "dogs"
    assert pluralize("octopus") == "octopuss"

# Design a function that takes a whole number
# of cents as input and produces a formatted
# money string (e.g. "$351.27") as output.

def format_money(cents: int) -> str:
    """Format cents as money."""
    dollars = cents // 100
    cents_left = cents % 100
    return ("$" + str(dollars) + "." + 
        pad_cents(cents_left)) 

def test_format_money():
    assert format_money(1) == "$0.01"
    assert format_money(200) == "$2.00"


# Convert an integer to a string, padded to
# a minimum field with of 2 with zeros.

def pad_cents(cents):
    """Zero pad to two digits."""
    if cents < 10:
        return "0" + str(cents)
    else:
        return str(cents)

def test_pad_cents():
    assert pad_cents(0) == "00"
    assert pad_cents(8) == "08"
    assert pad_cents(25) == "25"






