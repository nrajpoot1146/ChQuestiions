class Point:
    def __init__(self, x = 0, y = 0):
        self.x = x
        self.y = y
  
    def dist_from_origin(self):
        x = self.x
        y = self.y
        return ((x*x) + (y*y))**0.5
  
    ## the comparison magic methods
    def __lt__(self, value):
        return self.dist_from_origin() < value.dist_from_origin()

    def __gt__(self, value):
        return self.dist_from_origin() > value.dist_from_origin()
  
    def __eq__(self, value):
        return self.dist_from_origin() == value.dist_from_origin()
  
    def __le__(self, value):
        return self.dist_from_origin() <= value.dist_from_origin()
  
    def __ge__(self, value):
        return self.dist_from_origin() >= value.dist_from_origin()

    def __repr__(self):
        return "Point(" + repr(self.x) + "," + repr(self.y) + ")"


class Circle:

    def __init__(self, center = Point(), radius = 0):
        self.center = center
        self.radius = radius

    def center_dist_from_origin(self):
        return self.center.dist_from_origin()
  
    def edge_dist_from_origin(self):
        if self.radius > self.center_dist_from_origin():
            return self.radius - self.center_dist_from_origin()
        else:
            return self.center_dist_from_origin() - self.radius
  
    def area(self):
        return 3.14 * (self.radius * self.radius)
  
    def __lt__(self, value):
        return self.area() < value.area()
  
    def __gt__(self, value):
        return self.area() > value.area()
  
    def __eq__(self, value):
        return self.area() == value.area()
  
    def __le__(self, value):
        return self.area() <= value.area()
  
    def __ge__(self, value):
        return self.area() >= value.area()

    def __repr__(self):
        return "Circle(" + repr(self.center) + "," + repr(self.radius) + ")"