import time
import functools

# The @functools.wraps decorator uses functools.update_wrapper() to update
# special attributes like __name__ and __doc__ that are used in the introspection.


def duration(func):
    """Print the runtime of the decorated function"""
    @functools.wraps(func)
    def wrapper(*args, **kwargs):
        time_init = time.perf_counter()
        res = func(*args, **kwargs)
        time_end = time.perf_counter()
        run_time = time_end-time_init
        print(f'{func.__name__}() duration: {run_time:.7f} secs')
        return res
    return wrapper


def do_twice(func):
    """Call twice the decorated function"""
    @functools.wraps(func)
    def wrapper(*args, **kwargs):
        func(*args, **kwargs)
        func(*args, **kwargs)
        # return res
    return wrapper


@duration
def soma():
    total = 0
    for i in range(1000):
        total += i
    return total


@duration
def multiplicacao():
    total = 1
    for i in range(1, 1000):
        total *= i


# Nesting decorators
@do_twice
@duration
def twice_multiplicacao():
    total = 1
    for i in range(1, 1000):
        total *= i


print(soma())
print('-------------------------------------')
print(multiplicacao())
print('-------------------------------------')
print(twice_multiplicacao())
