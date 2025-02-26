
import sim
from sim.funs import *
from PIL.Image import Image

from pytest import approx
from collections import namedtuple

Vec2 = namedtuple('Vec2', ['x', 'y'])

# Our state is going to be
#  - The x,y posn of the cannonball as floats
#  - The x, y velcocity of the cannonball

BALL_VEL = 100  # pixels / second
GRAV     = 20   # pixels / second / second


def init():
    return (Vec2(0.0, 300.0), Vec2(BALL_VEL, 0.0))

def test_init():
    assert init() == (Vec2(approx(0.0), approx(300.0)), 
                      Vec2(approx(BALL_VEL), approx(0.0)))


def tick(state: tuple[Vec2, Vec2], dt) -> tuple[Vec2, Vec2]:
    (pos, vel) = state
    (px, py) = pos
    (vx, vy) = vel
    
    # Move the ball
    px = px + dt * vx
    py = py + dt * vy
    
    # Increase velocity by applying gravity
    vy = vy - dt * GRAV

    return (Vec2(px, py), Vec2(vx, vy))

def test_tick():
    state0 = init()
    state1 = tick(state0, 0.1)
    assert state1 == (Vec2(approx(0.0 + 0.1*100), 
                           approx(300.0)),
                      Vec2(approx(BALL_VEL),
                           approx(0.0 - 0.1*GRAV)))
    

def draw(state) -> Image:
    """Produce one frame visualizing our state."""
    (pos, vel) = state
    
    return place_at(empty_scene(),
                    circle(25),
                    int(pos.x),
                    600 - int(pos.y))

def test_draw():
    # Sadly, image equality doesn't work yet.
    # Hopefully we'll fix this in the HW.
    #assert draw((0, 0)) == some_image
    pass


def mouse_click(state, x: float, y: float, btn: str):
    """Handle a mouse click"""
    return init()

def test_mouse_click():
    pass


if __name__ == '__main__':
    sim.run()


