animals = ["cat", "dog", "gecko", "hedgehog"]
iterator = map(lambda s: s[::-1], animals)
print(f"Animals: {animals}")
print(f"Reverse: {list(iterator)}")
