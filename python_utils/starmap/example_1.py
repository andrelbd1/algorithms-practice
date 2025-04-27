from itertools import starmap


data: list[tuple[int, int]] = [(2, 4), (3, 3), (4, 3)]


def get_sum(*args: int) -> int:
    return sum(args)


sums: starmap = starmap(get_sum, data)
print(list(sums))  # [6, 6, 7]


powers: starmap = starmap(pow, data)
print(list(powers))  # [16, 27, 64]
