
import sim
from sim.funs import *

from collections import namedtuple
Posn = namedtuple('Posn', ['x', 'y'])

def init():
    ys = []
    for ii in range(0, 5):
        for jj in range(0, 3):
            ys.append(Posn(50 + 150 * ii, 50 + 150 * jj))
    return ys        
    
 
bat = mirror(contain(load_image("bat.png"), (200, 200)))

def draw(state):
    img = empty_scene()
    for item in state:
        (x, y) = item
        img = place_at(img, bat, x % 800, y % 600)
    return img


def tick(state):
    return state
    

def mouse_click(state, x, y, btn):
    return state


if __name__ == '__main__':
    sim.run()
