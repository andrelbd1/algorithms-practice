""" List Comprehension """
# List comprehension in Python are constructed as follows:
lst = [i for i in range(6)]
print(lst)

# Sum 2 in each list item
res = []
for i in lst:
    res.append(i+2)
print(res)

# Sum 2 in each list item using list comprehensions
res = [i+2 for i in lst]
print(res)

# Sum 2 in each even list item using list comprehensions
res = [i+2 if i % 2 == 0 and i != 0 else i for i in lst]
print(res)
