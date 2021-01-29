from bst import BinarySearchTree

tree = BinarySearchTree()
lst_element = [50, 25, 75, 10, 40, 60, 90]

for i in lst_element:
    tree.create(i)

assert tree.root.value == 50
assert tree.search(25).left.value == 10
assert tree.search(75).right.value == 90
assert tree.search(10).left is None
