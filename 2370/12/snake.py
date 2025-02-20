
import sim
from sim.funs import *
from PIL.Image import Image

from collections import namedtuple


Posn = namedtuple("Posn", ['x', 'y'])
# Position of snake segments and food will be
# in grid coordinates, not pixel coordinates.

# SnakeWorld is (food: Posn, snake: Snake, delay: int))
SnakeWorld = namedtuple("SnakeWorld", ['food', 'snake', 'delay'])

# Snake is (dd: Dir, segs: list[Posn])
Snake = namedtuple("Snake", ['dd', 'segs'])
#  - The segs field always contains at least one Posn.

# A Dir is one of "left", "right", "up", "down"



CELL_SIZE  = 40
CELLS_HIGH = 15
CELLS_WIDE = 20
FOOD_IMAGE = circle(int(CELL_SIZE / 2), "green")
SEG_IMAGE  = rectangle(CELL_SIZE - 2, CELL_SIZE - 2, "red")


def init() -> SnakeWorld:
    return SnakeWorld(Posn(5, 5),
                      Snake("up", [Posn(10, 10), Posn(10, 11)]),
                      10)


def draw(world: SnakeWorld) -> Image:
    (food, snake, delay) = world
    return draw_food(food, draw_snake(snake, empty_scene()))


def draw_food(food, img):
    (x, y) = food
    img = place_at(img, FOOD_IMAGE,
                   CELL_SIZE * x, CELL_SIZE * y)
    return img


def draw_snake(snake, img):
    (dd, segs) = snake
    for seg in segs:
        (x, y) = seg
        img = place_at(img, SEG_IMAGE, 
                       CELL_SIZE * x, CELL_SIZE * y)
    return img


def tick(world: SnakeWorld) -> SnakeWorld:
    (food, snake, delay) = world
    if delay == 0:
        snake = move_snake(snake)
        return SnakeWorld(food, snake, 10)
    else:
        return SnakeWorld(food, snake, delay - 1)


def move_snake(snake: Snake) -> Snake:
    (dd, segs) = snake
    head = move_head(segs[0], dd)
    segs = [head] + segs[:-1]
    return Snake(dd, segs)
    

def move_head(seg: Posn, dd: str):
    (x, y) = seg  
    if dd == "left": return Posn(x - 1, y)
    if dd == "right": return Posn(x + 1, y)
    if dd == "up": return Posn(x, y - 1)
    if dd == "down": return Posn(x, y + 1)
    raise Exception("bad direction: " + dd)


def test_move_head():
    assert move_head(Posn(5, 5), "up") == Posn(5, 4)
    assert move_head(Posn(5, 5), "down") == Posn(5, 6)
    assert move_head(Posn(5, 5), "left") == Posn(4, 5)
    assert move_head(Posn(5, 5), "right") == Posn(6, 5)



def key_press(world: SnakeWorld, key: str) -> SnakeWorld:
    if key in ["up", "down", "left", "right"]:
        snake = Snake(key, world.snake.segs)
        return SnakeWorld(world.food, snake, world.delay)
    else:
        return world


if __name__ == '__main__':
    sim.run()
