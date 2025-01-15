from collections import defaultdict

'''In this example a default value is a empty list.'''
items: list[tuple[str, int]] = [('a', 1), ('b', 2), ('a', 3), ('c', 4), ('a', 5), ('b', 6)]

d: defaultdict[str, list] = defaultdict(list)

for k, v in items:
    d[k].append(v)

print(dict(d))


'''In this example we a have a dictionary counting chars from a string.'''
d: defaultdict[str, int] = defaultdict(int)

string: str = 'yo mamma'
for c in string:
    d[c] += 1

print(d.items())
