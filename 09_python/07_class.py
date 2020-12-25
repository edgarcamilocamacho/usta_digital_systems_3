
class MiClase():

    def __init__(self, _x, _y):
        self.x = _x
        self.y = _y

    def increase_x(self):
        self.x += 1

obj = MiClase(5, 2)

print(obj.x)

obj.increase_x()

print(obj.x)

