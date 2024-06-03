### [DFS: Connected Cell in a Grid](https://www.hackerrank.com/challenges/ctci-connected-cell-in-a-grid/problem)
- Consider a matrix where each cell contains either a 0 or a 1 and any cell containing a 1 is called a filled cell. Two cells are said to be connected if they are adjacent to each other horizontally, vertically, or diagonally. In the diagram below, the two colored regions show cells connected to the filled cells. Black on white are not connected.
- If one or more filled cells are also connected, they form a region. Note that each cell in a region is connected to at least one other cell in the region but is not necessarily directly connected to all the other cells in the region.


- Example:
````bash
        Input: 1 1 0 0 0 1
               0 1 1 0 0 0
               0 O O 1 0 0
        Output: 5
        Explanation: It has 5 connected cells.
````

- [Solution](main.py)


### [Back](../../README.md)