
import sim
from sim.funs import *

from PIL.Image import Image

# Application state:
# "state" means "what changes as the simulation
# progresses"

bat = mirror(contain(
    load_image("bat.png"), 
    (200, 200)))


def init() -> tuple[int, int]:
    """Produces the initial state (x, y coordinates)
       for our flying bat."""
    return (0, 0)

def test_init():
    assert init() == (0, 0)


def tick(bat_posn: tuple[int, int]) -> tuple[int, int]:
    """Handle time passing, produce a new state."""
    (bat_x, bat_y) = bat_posn
    bat_x = (bat_x + 5) % 800
    bat_y = (bat_y - 2) % 600
    return (bat_x, bat_y)

def test_tick():
    assert tick((0, 0)) == (5, 598)
    assert tick((5, 598)) == (10, 596)


def draw(bat_posn: tuple[int, int]) -> Image:
    """Produce one frame visualizing our state."""
    print(bat_posn)
    (bat_x, bat_y) = bat_posn
    return place_at(empty_scene(),
                    bat,
                    bat_x,
                    bat_y)

def test_draw():
    # Sadly, image equality doesn't work yet.
    # Hopefully we'll fix this in the HW.
    #assert draw((0, 0)) == some_image
    pass


def mouse_click(bat_posn: tuple[int, int], x: float, y: float, btn: str) -> tuple[int, int]:
    """Handle a mouse click"""
    return (int(x), int(y))

def test_mouse_click():
    assert mouse_click((0, 0), 200, 98, "left") == (200, 98)


if __name__ == '__main__':
    sim.run()


