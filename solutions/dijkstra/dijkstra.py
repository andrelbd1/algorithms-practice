from math import inf

class Dijkstra:
    def __init__(self, graph):
        self.graph = graph
        self.n_vertices = len(graph)

    def print_result(self, dist, target=None):
        if target:
            return dist[target]

        print("Vertex \t Distance from Source")
        for node in range(self.n_vertices):
            print(node, "\t\t", dist[node])

    def min_distance(self, dist, visited):        
        min = inf # Initialize minimum distance for next node 
        for v in range(self.n_vertices): # get nearest vertex not visited
            if dist[v] < min and visited[v] == False:
                min = dist[v]
                min_index = v

        return min_index

    def dijkstra(self, src, target=None): # O(n2)
        visited = [False] * self.n_vertices
        dist = [inf] * self.n_vertices
        dist[src] = 0

        for _ in range(self.n_vertices):
            # Get the minimum distance vertex not visited yet.
            # u is always equal to src in first iteration.
            u = self.min_distance(dist, visited)
            visited[u] = True

            # Update distance value of the adjacent vertices
            for v in range(self.n_vertices):
                if (self.graph[u][v] > 0 and # Check if has edge
                        visited[v] == False and
                        dist[v] > dist[u] + self.graph[u][v]):
                    dist[v] = dist[u] + self.graph[u][v]

        return self.print_result(dist, target)