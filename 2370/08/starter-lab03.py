
import sim
from sim.funs import *
from PIL.Image import Image

from pytest import approx
from collections import namedtuple

import math
import random


BAT_X = 500
MOS_Y = 400

BAT = mirror(contain(load_image("bat.png"), (200, 200)))
MOS = mirror(contain(load_image("mosquito.png"), (75, 75)))


State = namedtuple('State', ['bat_y', 'mos_x'])


def move_bat(bat_y, key):
    # FIXME: Move bat
    return bat_y + 1

def test_move_bat():
    assert move_bat(10, "up") == 5 
    assert move_bat(10, "down") == 15
    assert move_bat(0, "up") == 0
    assert move_bat(600, "down") == 600
    assert move_bat(20, "left") == 20

    
def move_mosquito(mos_x):
    # FIXME: Move Mosquito
    return 100

def test_move_mosquito():
    # FIXME: Tests
    assert False


def bat_caught_mosquito(state):
    # FIXME: Code
    return True

def test_bat_caught_mosquito():
    assert not bat_caught_mosquito(State(25, 18))
    assert bat_caught_mosquito(State(410, 507))

    
def init() -> State:
    return State(100, 100)

def test_init():
    # This test is fine for lab03.
    assert init() == State(100, 100)


def draw(state: State) -> Image:
    (bat_y, mos_x) = state
    
    bg = empty_scene()
    aa = place_at(bg, BAT, BAT_X, bat_y)
    bb = place_at(aa, MOS, mos_x, MOS_Y)
    return bb

def test_draw():
    # This test is fine for lab03.
    assert type(draw(State(100, 100))) == Image


def tick(state: State) -> State:
    (bat_y, mos_x) = state
    if bat_caught_mosquito(state):
        mos_x = 100
    else:
        mos_x = move_mosquito(mos_x)
    return State(bat_y, mos_x)

def test_tick():
    assert False


def key_press(state, key):
    (bat_y, mos_x) = state
    bat_y = move_bat(bat_y, key)
    return State(bat_y, mos_x)

def test_key_press():
    assert False
    


if __name__ == '__main__':
    sim.run()
