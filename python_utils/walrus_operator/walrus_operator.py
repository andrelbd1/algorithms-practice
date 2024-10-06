# Walrus Operator
## Hello, Walrus! 
## To get a first impression of what assignment expressions are all about,
## start your REPL and play around with the following code:
walrus = False
print(walrus)

(walrus := True)
print(walrus)


## Dictionaries
numbers = [2, 8, 0, 1, 1, 9, 7, 7]

'''Note that both the sum and the length of the numbers list are calculated twice.'''
description = {
    "length": len(numbers),
    "sum": sum(numbers),
    "mean": sum(numbers) / len(numbers),
}
print(description)

'''The variables num_length and num_sum are only used to optimize the calculations 
inside the dictionary. By using the walrus operator, you can make this role clearer'''
description = {
    "length": (num_length := len(numbers)),
    "sum": (num_sum := sum(numbers)),
    "mean": num_sum / num_length,
}
print(description)


## List
'''Here, you filter the numbers list and leave the positive results from applying slow().
The problem with this code is that this expensive function is called twice.
'''
def slow(x):
    return x-2

numbers = [7, 6, 1, 4, 1, 8, 0, 6]
results = [slow(num) for num in numbers if slow(num) > 0]
print(results)

'''You can rewrite the list comprehension using the walrus operator as follows,
Note that the parentheses around value := slow(num) are required.
This version is effective and readable, and it communicates the intent of the code well.'''
results = [value for num in numbers if (value := slow(num)) > 0]
print(results)


'''Here, you first capture all city names that start with "B". 
Then, if there’s at least one such city name, you print out the 
first city name starting with "B".'''
cities = ['Monaco', 'Vancouver', 'Rio de Janeiro', 'Berlin', 'La Paz', 'Bogota', 'Dallas']

if any((witness := city).startswith("B") for city in cities):
    print(f"{witness} starts with B")
else:
    print("No city name starts with B")

'''You can more clearly see what’s happening by wrapping .startswith("B") in a function that
also prints out which item is being checked:'''
def starts_with_b(name):
    print(f"Checking {name}: {(result := name.startswith('B'))}")
    return result

any(starts_with_b(city) for city in cities)
all(starts_with_b(city) for city in cities)
