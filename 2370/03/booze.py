
# Which contains more alcohol?
#  - A 12 oz bottle of 10 proof beer
#  - A 2 oz shot of 80 proof tequila

# Percentage of alcohol by volume
# is 0.5 * proof

from pytest import approx

def alcohol_volume(proof, drink_vol_oz):
    pct = proof * 0.5
    frac = pct / 100.0
    return drink_vol_oz * frac

def test_alcohol_volume():
    assert alcohol_volume(10, 12) == approx(0.6)
    assert alcohol_volume(80, 2) == approx(0.8)

def test_always_fails():
    assert 5 == approx(5.5)
    