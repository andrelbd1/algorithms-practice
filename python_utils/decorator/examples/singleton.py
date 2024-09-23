import functools

def singleton(cls):
    """Make a class a Singleton class (only one instance)"""
    @functools.wraps(cls)
    def wrapper_singleton(*args, **kwargs):
        if wrapper_singleton.instance is None:
            wrapper_singleton.instance = cls(*args, **kwargs)
        return wrapper_singleton.instance
    wrapper_singleton.instance = None
    return wrapper_singleton

@singleton
class Foo:
    pass

first_one = Foo()
another_one = Foo()
print(f'{first_one = }')
print(f'{another_one = }')
print(f'first_one is another_one: {first_one is another_one}')