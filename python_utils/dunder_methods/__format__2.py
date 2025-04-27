from typing import Any


class Book:
    def __init__(self, title: str, pages: int) -> None:
        self.title = title
        self.pages = pages

    def __format__(self, format_spec: Any) -> str:
        match format_spec:
            case 'time':
                return f'Read time: {self.pages / 60:.2f}h'
            case 'caps':
                return self.title.upper()
            case _:
                raise ValueError('Unknown specifier for Book()')


def main() -> None:
    harry_potter: Book = Book('Harry Potter', 300)
    lord_rings: Book = Book('Lord of the Rings', 800)

    print(f'{harry_potter:caps}')  # HARRY POTTER
    print(f'{harry_potter:time}')  # Read time: 5.00h
    print('---------------------')
    print(f'{lord_rings:caps}')  # LORD OF THE RINGS
    print(f'{lord_rings:time}')  # Read time: 13.33h


if __name__ == '__main__':
    main()
