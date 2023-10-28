class Monostate:
        __shared_state = {"1":"2"}

        def __init__(self):
            self.x = 1
            self.__dict__ = self.__shared_state
            pass

b = Monostate()
b1 = Monostate()
b.x=4

print("Monostate Object 'b':",b)
print("Monostate Object 'b1':",b1)
print("Object State 'b':",b.__dict__)
print("Object State 'b1':",b1.__dict__)