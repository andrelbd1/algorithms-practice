from collections import ChainMap

mom = {"name": "Jane", "age": 31}
dad = {"name": "John", "age": 35}
son = {"name": "Mike", "age":  5}

family = ChainMap(son, mom, dad)
print(family)  # ChainMap({'name': 'Mike', 'age': 0},{'name': 'Jane', 'age': 31},{'name': 'John', 'age': 35})
print(family.parents)  # ChainMap({'name': 'Jane', 'age': 31}, {'name': 'John', 'age': 35})
