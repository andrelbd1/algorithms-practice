from collections import ChainMap

# Merge dicts using union operator
d1 = {'a': 1, 'b': 2}
d2 = {'b': 3, 'c': 4}
print(f"Union dicts: {d1 | d2}")  # Union dicts: {'a': 1, 'b': 3, 'c': 4}

# Merge dicts using ChainMap
cm: ChainMap[str, int] = ChainMap(d1, d2)
print(f"ChainMap: {cm}")  # ChainMap: ChainMap({'a': 1, 'b': 2}, {'b': 3, 'c': 4})

# Get
print(f"ChainMap: {cm.maps[0]=}")  # ChainMap: cm.maps[0]={'a': 1, 'b': 2}
print(f"ChainMap: {cm.maps[1]=}")  # ChainMap: cm.maps[1]={'b': 3, 'c': 4}
print(f"ChainMap: {cm['b']=}")  # ChainMap: cm['b']=2
print(f"ChainMap: {cm.get('b')=}")  # ChainMap: cm.get('b')=2

# Append
cm.maps.append({'d': 5})
print(f"ChainMap: {cm}")  # ChainMap: ChainMap({'a': 1, 'b': 2}, {'b': 3, 'c': 4}, {'d': 5})
