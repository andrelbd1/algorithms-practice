from functools import singledispatch
from typing import Any


@singledispatch
def process(data: Any):
    print(f"Processing generic data: {data}")


@process.register
def _(data: int | float):
    print(f"Processing a number: {data}")


@process.register
def _(data: str):
    print(f"Processing a string: {data}")


process([1, 2, 3])  # Output: Processing generic data: [1, 2, 3]
process(10)         # Output: Processing a number: 10
process(5.5)        # Output: Processing a number: 5.5
process("Hello")    # Output: Processing a string: Hello
