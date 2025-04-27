from operator import itemgetter


items: dict[str, int] = {
    "a": 1,
    "b": 2,
    "c": 3,
    "d": 4,
    "e": 5,
}
elements: dict[str, int] = {
    "a": 200,
    "b": 400,
    "c": 600,
    "d": 800,
    "e": 1000,
}

selected_items: itemgetter = itemgetter("a", "c", "e")
print(selected_items(items))  # Output: (1, 3, 5)
print(selected_items(elements))  # Output: (200, 600, 1000)
