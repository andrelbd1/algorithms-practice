import sys

def shortest_path(grid):

    total_row = len(grid)
    total_col = len(grid[0])

    start_row = -1
    start_col = -1

    # Get the P position:
    for curr_row in range(total_row):
        for curr_col in range(total_col):
            if grid[curr_row][curr_col] == "P":
                start_row = curr_row
                start_col = curr_col
                break
    
    visited = [[] for i in range(total_row)]
    
    directions = [[0,1],[1,0],[-1,0],[0,-1]]
    queue = []
    queue.append((start_row,start_col))
    
    count = 0
    while queue:
        size = len(queue)

        for i in range(size):
            curr_pos = queue[0]
            queue.remove(curr_pos)

            row = curr_pos[0]
            col = curr_pos[1]

            visited[row].append(col)

            if grid[row][col] == "F":
                return count
            
            for d in directions:
                row_next = row+d[0]
                col_next = col+d[1]
                
                #to do verify if is a reliable position
                if row_next >= 0 and row_next < total_row and col_next >= 0 and col_next < total_col:
                    if not grid[row_next][col_next] == "X":
                        if not col_next in visited[row_next]:
                            queue.append((row_next, col_next))
    
        count+=1

    return -1

if __name__ == '__main__':
    input_file = str(sys.argv[1])

    f = open(input_file, "r")
    m = []
    while True:        
        nstr = f.readline().rstrip()
        if len(nstr) == 0:
            break
        
        m.append(nstr.split(" "))

    print(shortest_path(m))