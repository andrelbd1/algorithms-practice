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
        while len(queue) > 0:
            node = queue[0]
            queue.remove(node)

            visited.append(node)
            if value == node:
                print("path: ",visited)
                return value

            for next_node in self.graph[node]:
                if not next_node in visited and not next_node in queue:
                    queue.append(next_node)

        print("path: Not found")
        return -1