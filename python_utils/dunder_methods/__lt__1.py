from typing import Self


class Fruit:
    def __init__(self, *, name: str, grams: float) -> None:
        self.name = name
        self.grams = grams

    def __lt__(self, other: Self) -> bool:
        return self.grams < other.grams


def main() -> None:
    f1: Fruit = Fruit(name='Apple', grams=100)
    f2: Fruit = Fruit(name='Banana', grams=150)

    print(f1 > f2)  # False
    print(f2 > f1)  # True


if __name__ == '__main__':
    main()
