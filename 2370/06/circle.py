
from math import pi
from pytest import approx

from collections import namedtuple


Circle = namedtuple('Circle', ['color', 'rad'])
#  - color is a word like "red"
#  - rad is in meters

# Design a function that  takes a circle 
# and returns its area.

def circle_area(circle: Circle) -> float:
    """Returns the area of the circle"""
    #(color, rad) = circle
    #return pi * pow(rad, 2)
    return pi * pow(circle.rad, 2)

def test_circle_area():
    c1 = Circle("green", 5.5)
    yy = 95.03317777109123
    assert circle_area(c1) == approx(yy) 
