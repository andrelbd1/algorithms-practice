import math
from collections import Counter
from itertools import combinations

def min_distance(dist, visited):
    min_dist = math.inf # Initialize minimum distance for next node
    for v in dist.keys():
        if dist[v] < min_dist and visited[v] is False: # get nearest vertex not visited
            min_dist = dist[v]
            vertice = v
    return vertice
            

def dijkstra(graph, src, target):
    visited = {i: False for i in range(1, len(graph)+1)}
    dist = {i: math.inf for i in range(1, len(graph)+1)}
    dist[src] = 0 
    n_vertice = len(graph)
    
    for _ in range(n_vertice):
        u = min_distance(dist, visited) # Get the minimum distance vertex not visited yet.
        visited[u]=True
        
        for v in graph[u]: # Update distance value of the adjacent vertices
            if visited[v] is False and dist[v] > dist[u] + 1:
                dist[v] = dist[u] + 1
                
    return dist[target]
    

def findShortest(graph_nodes, graph_from, graph_to, ids, val):
    count_colors = Counter(ids)
    if count_colors[val]==1:
        return -1
    
    graph = {i: [] for i in range(1, graph_nodes+1)}
    for u, v in zip(graph_from, graph_to):
        graph[u].append(v)
        graph[v].append(u)
    
    nodes = [i+1 for i in range(len(ids)) if ids[i]==val]  # nodes to check paths
    from_to = combinations(nodes, 2)
    
    min_distance = math.inf
    for src, target in from_to:
        min_distance = min(min_distance, dijkstra(graph, src, target))
        if min_distance==1:
            break
    
    return -1 if min_distance == math.inf else min_distance