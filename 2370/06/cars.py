
from collections import namedtuple
from pytest import approx
from math import pi

# A Fuel Barrel is a cylendar containing
# liquid fuel.

FuelBarrel = namedtuple('FuelBarrel', 
                        ['rad', 'height', 'fuel'])
# rad: float - radius in meters
# height: float - height in meters
# fuel: One of "E0", "E10", "E100", "Diesel"

# Energy densities:
#  - E0 is 35 MJ/L
#  - E10 is 33 MJ/L
#  - E100 is 22 MJ/L
#  - Diesel is 38 MJ/L

def energy(fuel: str) -> float:
    """Get energy density in MJ/L"""
    if fuel == 'E0':
        return 35.0
    if fuel == 'E10':
        return 33.0
    if fuel == 'E100':
        return 22.0
    if fuel == 'diesel':
        return 38.0
    raise Exception("Bad fuel")
    

def test_energy():
    assert energy('E0') == approx(35.)
    assert energy('E10') == approx(33.)
    assert energy('E100') == approx(22.)
    assert energy('diesel') == approx(38.)

# Given a fuel barrel, calculate the total
# contained energy in megajoules.
 
def total_energy(barrel: FuelBarrel) -> float:
    """Calc total energy in MJ."""
    (rad, height, fuel) = barrel
    vL = 1000 * pi * pow(rad, 2) * height
    return energy(fuel) * vL

def test_total_energy():
    b1 = FuelBarrel(1.0, 5.0, "diesel")
    vol_m3 = pi * pow(b1.rad, 2) * b1.height
    vol_liters = 1000 * vol_m3
    energy_mj = 38 * vol_liters
    assert total_energy(b1) == approx(energy_mj)
    