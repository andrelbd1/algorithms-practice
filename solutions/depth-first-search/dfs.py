class DepthFirstSearch:
    def __init__(self, graph):
        self.graph = graph

    def dfs(self, root, value):
        print()
        print("root: ",root)
        print("value: ",value)
        stack = []
        stack.append(root)
        
        visited = []

        #LIFO
        while stack:
            node = stack.pop(len(stack)-1)

            visited.append(node)
            if value == node:
                print("path: ",visited)
                return value

            for next_node in self.graph[node]:
                if next_node not in visited and next_node not in stack:
                    stack.append(next_node)

        print("path: Not found")
        return -1