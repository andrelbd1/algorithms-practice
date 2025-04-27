from typing import Self


class Fruit:
    def __init__(self, *, name: str, grams: float) -> None:
        self.name = name
        self.grams = grams

    def __eq__(self, other: Self) -> bool:
        return self.name == other.name


def main() -> None:
    f1: Fruit = Fruit(name='Apple', grams=100)
    f2: Fruit = Fruit(name='Banana', grams=150)
    f3: Fruit = Fruit(name='Apple', grams=200)

    print(f1 == f2)
    print(f1 == f3)


if __name__ == '__main__':
    main()
