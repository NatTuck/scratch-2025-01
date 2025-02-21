
import sim
from sim.funs import *
from PIL.Image import Image

from random import randint
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
WALL_IMAGE = rectangle(CELL_SIZE, CELL_SIZE, "blue")


def init() -> SnakeWorld:
    return SnakeWorld(Posn(5, 5),
                      Snake("up", [Posn(10, 10), Posn(10, 11)]),
                      10)


def draw(world: SnakeWorld) -> Image:
    (food, snake, delay) = world
    return draw_borders(
        draw_food(food, draw_snake(snake, empty_scene())))



def draw_borders(img):
    img = place_at(
        img,
        rectangle(CELL_SIZE * CELLS_WIDE, CELL_SIZE, "blue"),
        CELL_SIZE * (CELLS_WIDE / 2),
        CELL_SIZE * 0)
    img = place_at(
        img,
        rectangle(CELL_SIZE * CELLS_WIDE, CELL_SIZE, "blue"),
        CELL_SIZE * (CELLS_WIDE / 2),
        CELL_SIZE * CELLS_HIGH)
    img = place_at(
        img,
        rectangle(CELL_SIZE, CELL_SIZE * CELLS_HIGH, "blue"),
        CELL_SIZE * 0,
        CELL_SIZE * (CELLS_HIGH / 2))
    return img


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


def snake_hit_self(snake: Snake) -> bool:
    (dd, segs) = snake
    head = segs[0]
    for seg in segs[1:]:
        if head == seg:
            return True
    return False
    

def snake_hit_wall(snake: Snake) -> bool:
    (dd, segs) = snake
    head = segs[0]
    return (head.x >= CELLS_WIDE or head.y >= CELLS_HIGH
            or head.x <= 0 or head.y <= 0)
    

def game_over(snake: Snake) -> bool:
    return snake_hit_self(snake) or snake_hit_wall(snake)


def tick(world: SnakeWorld) -> SnakeWorld:
    (food, snake, delay) = world
    if delay == 0:
        snake = move_snake(snake, food)
        food = tick_food(food, snake)
        
        if game_over(snake):
            return init()
        else:
            return SnakeWorld(food, snake, 10)
    else:
        return SnakeWorld(food, snake, delay - 1)


def tick_food(food: Posn, snake: Snake) -> Posn:
    head = snake.segs[0]
    if head == food:
        return Posn(randint(1, CELLS_WIDE - 1), 
                    randint(1, CELLS_HIGH - 1))
    return food


def move_snake(snake: Snake, food: Posn) -> Snake:
    (dd, segs) = snake
    head = move_head(segs[0], dd)
    if head == food:
        segs = [head] + segs
    else:
        segs = [head] + segs[:-1]
    return Snake(dd, segs)
    

def move_head(seg: Posn, dd: str) -> Posn:
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
