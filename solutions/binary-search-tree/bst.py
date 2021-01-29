class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


class BinarySearchTree:
    def __init__(self):
        self.root = None

    def create(self, value):
        if self.root is None:
            self.root = Node(value)
        else:
            curr = self.root

            while True:
                if value < curr.value:
                    if curr.left is None:
                        curr.left = Node(value)
                        break
                    else:
                        curr = curr.left
                else:
                    if curr.right is None:
                        curr.right = Node(value)
                        break
                    else:
                        curr = curr.right

    def search(self, value):
        if self.root is None:
            return None
        else:
            curr = self.root

            while True:
                if value == curr.value:
                    return curr
                else:
                    if value < curr.value:
                        if curr.left is None:
                            return None
                        else:
                            curr = curr.left
                    else:
                        if curr.right is None:
                            return None
                        else:
                            curr = curr.right
