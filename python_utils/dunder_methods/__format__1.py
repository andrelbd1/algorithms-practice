class Fruit:
    def __init__(self, *, name: str, grams: float) -> None:
        self.name = name
        self.grams = grams

    def __format__(self, format_spec: str) -> str:
        match format_spec:
            case 'kg':
                return f'{self.grams / 1000:.2f} kg'
            case 'lb':
                return f'{self.grams / 453.5924:.2f} lb'
            case 'oz':
                return f'{self.grams / 28.3495:.2f} oz'
            case 'desc':
                return f'{self.grams} g of {self.name}'
            case _:
                return f'Unknown format: {format_spec}'


def main() -> None:
    f1: Fruit = Fruit(name='Apple', grams=2500)
    print(f'{f1:kg}')  # 2.50 kg
    print(f'{f1:lb}')  # 5.51 lb
    print(f'{f1:oz}')  # 88.18 oz
    print(f'{f1:desc}')  # 2500 g of Apple
    print(f'{f1:unk}')  # Unknown format: unk


if __name__ == '__main__':
    main()
