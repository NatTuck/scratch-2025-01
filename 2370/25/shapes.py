
from math import pi

class Shape:
    def area(self):
        raise Exception("not implemented")

    def is_big(self):
        return self.area() > 10


class Circle(Shape):
    color = "green"

    def __init__(self, radius):
        self.radius = radius
        
    def get_color(self):
        return self.color
    
    def area(self):
        return pi * pow(self.radius, 2)
    
    def set_color(self, color):
        self.color = color
    

class Square(Shape):
    def __init__(self, length):
        self.length = length
    
    def area(self):
        return self.length * self.length
    

def total_area(xs: list[Shape]) -> float:
    total = 0.0
    for item in xs:
        total += item.area()
    return total


items = [Square(5), Circle(7), Square(29)]


class Obj:
    pass
    
    
    
