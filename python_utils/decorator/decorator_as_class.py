import functools

# The typical way to maintain state in Python is by using classes.
# Recall that the decorator syntax @decorator is just a quicker way of saying func = decorator(func). 
# Therefore, if decorator is a class, it needs to take func as an argument in its .__init__() initializer. 
# Furthermore, the class instance needs to be callable so that it can stand in for the decorated function.
# For a class instance to be callable, you implement the special .__call__() method.
# The .__call__() method is executed each time you try to call an instance of the class:

class CountCalls:
    def __init__(self, func):
        functools.update_wrapper(self, func)
        self.func = func
        self.num_calls = 0

    def __call__(self, *args, **kwargs):
        self.num_calls += 1
        print(f"Call {self.num_calls} of {self.func.__name__}()")
        return self.func(*args, **kwargs)

@CountCalls
def say_hi():
    print("Hi!")

for i in range(4):
    say_hi()