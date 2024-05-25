def roadsAndLibraries(n, c_lib, c_road, cities):
    if c_lib<=c_road or n==1 or not cities:
        return n*c_lib

    graph = {i: [] for i in range(1,n+1)}
    for c in cities:
        graph[c[0]].append(c[1])
        graph[c[1]].append(c[0])

    cost=0
    visited = {i: False for i in range(1,n+1)}

    ## Modified DFS:
    for n in range(1,n+1):
        if visited[n]:
            continue
        visited[n] = True
        cost+=c_lib
        queue=graph[n]
        while queue:
            c = queue.pop()
            if not visited[c]:
                visited[c] = True
                cost+=c_road
                for adj in graph[c]:
                    if not visited[adj] and adj not in queue:
                        queue.append(adj)

    return cost