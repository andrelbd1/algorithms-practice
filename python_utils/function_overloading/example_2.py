from functools import singledispatchmethod
from typing import Any


class Bar:
    @singledispatchmethod
    def process(self, data: Any):
        print(f"Processing generic data: {data}")

    @process.register
    def _(self, data: int | float):
        print(f"Processing a number: {data}")

    @process.register
    def _(self, data: str):
        print(f"Processing a string: {data}")


bar = Bar()
bar.process([1, 2, 3])  # Output: Processing generic data: [1, 2, 3]
bar.process(10)         # Output: Processing a number: 10
bar.process(5.5)        # Output: Processing a number: 5.5
bar.process("Hello")    # Output: Processing a string: Hello
