from dataclasses import dataclass


@dataclass(kw_only=True)
class Fruit:
    name: str
    grams: float


class Basket:
    def __init__(self, *, fruits: list[Fruit]) -> None:
        self.fruits = fruits

    def __getitem__(self, item: str) -> list[Fruit]:
        return [fruit for fruit in self.fruits if fruit.name.lower() == item.lower()]


def main() -> None:
    fruits: list[Fruit] = [Fruit(name='Apple', grams=2500),
                           Fruit(name='Apple', grams=50),
                           Fruit(name='Banana', grams=1000),
                           Fruit(name='Banana', grams=9000),
                           Fruit(name='Orange', grams=1500),
                           Fruit(name='Orange', grams=1000),
                           ]
    basket: Basket = Basket(fruits=fruits)
    matches: list[Fruit] = basket['orange']
    print(f'Matches: {matches}')  # Matches: [Fruit(name='Orange', grams=1500), Fruit(name='Orange', grams=1000)]
    print(f'Total: {len(matches)}')  # Total: 2


if __name__ == '__main__':
    main()
