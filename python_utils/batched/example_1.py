from itertools import batched

numbers: list[int] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
my_batched: batched = batched(numbers, n=3)

for i in my_batched:
    print(i)
# Output: (1, 2, 3)
# Output: (4, 5, 6)
# Output: (7, 8, 9)
# Output: (10,)

print(list(my_batched))  # Output: [(1, 2, 3), (4, 5, 6), (7, 8, 9), (10,)]
