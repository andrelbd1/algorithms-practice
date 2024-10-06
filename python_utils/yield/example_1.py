def random_numbers():
    for i in range(10):
        yield i

gen = random_numbers()

print(next(gen))
print(next(gen))
print(next(gen))
print(next(gen))
print(list(gen))