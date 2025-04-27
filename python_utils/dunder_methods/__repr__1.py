class Fruit:
    def __init__(self, *, name: str, grams: float) -> None:
        self.name = name
        self.grams = grams

    def __str__(self) -> str:
        return f'{self.name} ({self.grams} g)'

    def __repr__(self) -> str:
        return f'Fruit(name="{self.name}", grams={self.grams})'


def main() -> None:
    f1: Fruit = Fruit(name='Apple', grams=1500)
    f2: Fruit = Fruit(name='Banana', grams=2000)
    f3: Fruit = Fruit(name='Orange', grams=1000)
    fruits: list[Fruit] = [f1, f2, f3]
    for fruit in fruits:
        print(f'str: {fruit}')
        # str: Apple (1500 g)
        # str: Banana (2000 g)
        # str: Orange (1000 g)
    for fruit in fruits:
        print(f'repr: {repr(fruit)}')
        # repr: Fruit(name="Apple", grams=1500)
        # repr: Fruit(name="Banana", grams=2000)
        # repr: Fruit(name="Orange", grams=1000)


if __name__ == '__main__':
    main()
