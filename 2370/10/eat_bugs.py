
import sim
from sim.funs import *
from PIL.Image import Image

import math
from random import randint
from collections import namedtuple


Posn = namedtuple("Posn", ['x', 'y'])
World = namedtuple("World", ['bat', 'bugs'])


BAT = mirror(contain(load_image("bat.png"), (200, 200)))
MOS = mirror(contain(load_image("mosquito.png"), (75, 75)))


def init():
    return World(Posn(300, 400), [])


def draw_bugs(scene: Image, bugs: list[Posn]) -> Image:
    """Add bugs to the scene."""
    for bug in bugs:
        (bx, by) = bug
        scene = place_at(scene, MOS, bx, by)
    return scene


def draw(state: World) -> Image:
    (bat, bugs) = state    
    scene = draw_bugs(empty_scene(), bugs)
    return place_at(scene, BAT, bat.x, bat.y) 


def clamp(xx: int, min_xx: int, max_xx: int) -> int:
    """Clamp an integer between min_xx and max_xx"""
    if xx < min_xx:
        return min_xx
    if xx > max_xx:
        return max_xx
    return xx


def move_bugs(bugs: list[Posn]) -> list[Posn]:
    """Bugs move."""
    ys = []
    for bug in bugs:
        bx = clamp(bug.x + randint(-2, 2), 0, 800)
        by = clamp(bug.y + randint(-2, 2), 0, 600)
        ys.append(Posn(bx, by))
    return ys
    

def dist(p0: Posn, p1: Posn) -> float:
    """Distance between two posns."""
    dx = p1.x - p0.x
    dy = p1.y - p0.y
    return math.sqrt(dx*dx + dy*dy)


def nearest_bug(bat: Posn, bugs: list[Posn]) -> Posn:
    """Find the nearest mosquito to the bat. We know
    the bugs list is non-empty."""
    nearest = bugs[0]
    for bug in bugs[1:]:
        if dist(bat, bug) < dist(bat, nearest):
            nearest = bug
    return nearest


def move_bat(bat: Posn, bugs: list[Posn]) -> Posn:
    """Move the bat towards the nearest mosquito."""
    if len(bugs) == 0:
        return bat
    
    bug = nearest_bug(bat, bugs)
    theta = math.atan2(bug.y - bat.y, bug.x - bat.x)
    bx = bat.x + math.cos(theta)
    by = bat.y + math.sin(theta)
    return Posn(bx, by)


def tick(state: World) -> World:
    """Update the world as time passes."""
    (bat, bugs) = state
    bugs = move_bugs(bugs)
    bat = move_bat(bat, bugs)

    # Eat bug
    ys = []
    for bug in bugs:
        if dist(bug, bat) > 5:
            ys.append(bug)

    return World(bat, ys)


def mouse_click(state, x, y, btn):
    (bat, bugs) = state
    bugs.append(Posn(x, y))
    return World(bat, bugs)

if __name__ == '__main__':
    sim.run()
