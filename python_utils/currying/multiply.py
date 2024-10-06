from typing import Callable

def mutiply_setup(a: float) -> Callable:
    def mutiply(b: float) -> float:
        return a * b
    return mutiply

double: Callable = mutiply_setup(2)
triple: Callable = mutiply_setup(3)

print(f'{double(100) = }')
print(f'{triple(100) = }')