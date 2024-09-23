import functools
from count_calls import CountCalls

def cache(func):
    """Keep a cache of previous function calls"""
    @functools.wraps(func)
    def wrapper_cache(*args, **kwargs):
        cache_key = args + tuple(kwargs.items())
        if cache_key not in wrapper_cache.cache:
            wrapper_cache.cache[cache_key] = func(*args, **kwargs)
        return wrapper_cache.cache[cache_key]
    wrapper_cache.cache = {}
    return wrapper_cache

@CountCalls
def fibonacci_straightforward(num):
    if num < 2:
        return num
    return fibonacci_straightforward(num - 1) + fibonacci_straightforward(num - 2)

@cache
@CountCalls
def fibonacci_memoization(num):
    if num < 2:
        return num
    return fibonacci_memoization(num - 1) + fibonacci_memoization(num - 2)

n=8
print(fibonacci_straightforward(n))
print(f'----------------------------------')
print(fibonacci_memoization(n))