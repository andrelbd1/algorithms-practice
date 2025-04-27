from typing import Self


class Fruit:
    def __init__(self, *, name: str, grams: float) -> None:
        self.name = name
        self.grams = grams

    def __or__(self, other: Self) -> Self:
        new_name = f'{self.name} & {other.name}'
        new_grams = self.grams + other.grams
        return Fruit(name=new_name, grams=new_grams)

    def __repr__(self) -> str:
        return f'Fruit(name={self.name}, grams={self.grams})'


def main() -> None:
    f1: Fruit = Fruit(name='Apple', grams=1500)
    f2: Fruit = Fruit(name='Banana', grams=2000)
    f3: Fruit = Fruit(name='Orange', grams=1000)

    combined: Fruit = f1 | f2 | f3
    print(combined)  # Fruit(name=Apple & Banana & Orange, grams=4500)


if __name__ == '__main__':
    main()
