def random_numbers():
    for i in range(3):
        yield i

def random_numbers_100():
    for i in range(100,105):
        yield i

def generator():
    yield from random_numbers()
    print('Next generator')
    yield from random_numbers_100()

if __name__ == '__main__':
    gen = generator()
    print(next(gen))
    print(next(gen))
    print(next(gen))
    print(list(gen))
