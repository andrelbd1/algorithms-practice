from operator import itemgetter


elements: list[int] = [1, 2, 3, 4, 5]
first_and_last: itemgetter = itemgetter(0, -1)

print(first_and_last(elements))  # Output: (1, 5)
