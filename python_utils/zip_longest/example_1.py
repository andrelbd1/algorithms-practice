from itertools import zip_longest

names: list[str] = ["Alice", "Bob", "Charlie"]
ages: list[int] = [1, 2, 3, 4, 5]
symbols: list[str] = ["@", "#", "$", "%", "&", "*", "!", "^", "~"]

zipped = zip_longest(names, ages, symbols, fillvalue=False)
print(list(zipped))
# Output:
#       [('Alice', 1, '@'),
#        ('Bob', 2, '#'),
#        ('Charlie', 3, '$'),
#        (False, 4, '%'),
#        (False, 5, '&'),
#        (False, False, '*'),
#        (False, False, '!'),
#        (False, False, '^'),
#        (False, False, '~')]
