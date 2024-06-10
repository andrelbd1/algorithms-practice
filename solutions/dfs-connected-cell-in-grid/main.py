from itertools import product

#
# Complete the 'maxRegion' function below.
#
# The function is expected to return an INTEGER.
# The function accepts 2D_INTEGER_ARRAY grid as parameter.
#

mv = list(product([-1, 0, 1], repeat=2))
mv.remove((0, 0))

def dfs(grid, n, m, visited, n_rows, n_cols):
    stack = [(n, m)]
    length = 0
    while stack:
        curr_n, curr_m = stack.pop(len(stack)-1)
        visited[curr_n][curr_m] = True
        length+=1
        for adj_n, adj_m in mv:
            adj_n += curr_n
            adj_m += curr_m
            if 0 > adj_n or adj_n >= n_rows or 0 > adj_m or adj_m >= n_cols:
                continue
            elif grid[adj_n][adj_m] == 1 and visited[adj_n][adj_m] is False and (adj_n, adj_m) not in stack:
                stack.append((adj_n, adj_m))
        
    return visited, length
    

def maxRegion(grid):
    n_rows = len(grid)
    n_cols = len(grid[0])
    
    visited=[[False]*n_cols for _ in range(n_rows)]
    l_region = 0
    
    for n in range(n_rows):
        for m in range(n_cols):
            if grid[n][m] == 1 and visited[n][m] is False:
                visited, length = dfs(grid, n, m, visited, n_rows, n_cols)
                l_region = max(length, l_region)
    
    return l_region