def bfs(w, h, area):
    dist=[]    
    for i in range(w):
        dist.append([area[i][j] for j in range(h)])

    maxDist=0
    q=[]
    for i in range(w):
        for j in range(h):
            if dist[i][j]==0:
                q.append([i,j])

    varX = [1, -1, 0, 0]
    varY = [0, 0, -1, 1]

    while len(q) != 0:
        x=q[0][0]
        y=q[0][1]
        maxDist=max(maxDist,dist[x][y])
        q.remove([x,y])

        for d in range(4):
            newx=x+varX[d]
            newy=y+varY[d]

            if (newx >= w) | (newy >= h) | (newx<0) | (newy<0):
                continue

            if(dist[newx][newy]==-1):
                dist[newx][newy] = dist[x][y]+1
                q.append([newx,newy])
    
    return maxDist

def buildOffices(before, w, h, row, col, area):
    if before == 0:
        return bfs(w,h,area)
    
    auxRow=row
    auxCol=col
    
    if col >= h:
        auxRow+=col//h
        auxCol+=col%h

    minDist = w+h
    for i in range(auxRow,w):
        for j in range(auxCol,h):
            area[i][j]=0 #make building
            val=buildOffices(before-1, w, h, i, j+1, area)
            minDist=min(minDist,val)

            area[i][j]=-1 #remove buildings

    return minDist

def findMinDistance(w, h, n):    
    area=[]
    for i in range(w):
        area.append([-1 for j in range(h)])

    return buildOffices(n,w,h,0,0,area)

findMinDistance(4,4,3) #2
findMinDistance(2,3,2) #1
findMinDistance(5,1,1) #2
