animals = ["cat", "dog", "gecko", "hedgehog"]
iterator = map(lambda s: s[::-1], animals)
print(f"Animals: {animals}")  # ['cat', 'dog', 'gecko', 'hedgehog']
print(f"Reverse: {list(iterator)}")  # ['tac', 'god', 'okceg', 'gohegdeh']
