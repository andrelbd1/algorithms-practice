class Multiply:
    def __init__(self, value: int) -> None:
        self.value = value

    def __call__(self, other_value: int) -> int:
        return self.value * other_value

double: Multiply = Multiply(2)
triple: Multiply = Multiply(3)

print(f'{double(100) = }')
print(f'{triple(100) = }')