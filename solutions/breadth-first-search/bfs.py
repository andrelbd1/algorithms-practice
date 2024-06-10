class BreadthFirstSearch:
    def __init__(self, graph):
        self.graph = graph

    def bfs(self, root, value):
        print()
        print("root: ",root)
        print("value: ",value)
        queue = []
        queue.append(root)
        
        visited = []

        #FIFO
        while queue:
            node = queue.pop(0)

            visited.append(node)
            if value == node:
                print("path: ",visited)
                return value

            for next_node in self.graph[node]:
                if next_node not in visited and next_node not in queue:
                    queue.append(next_node)

        print("path: Not found")
        return -1