### [Shortest Path to Get Food](https://leetcode.com/problems/shortest-path-to-get-food/)
- You are starving and you want to eat food as quickly as possible. You want to find the shortest path to arrive at a food cell.

You are given an m x n character matrix, grid, of these different types of cells:
- 'P' is your location. There is exactly one '*' cell.
- 'F' is a food cell. There may be multiple food cells.
- 'O' is free space, and you can travel through these cells.
- 'X' is an obstacle, and you cannot travel through these cells.

Return the length of the shortest path for you to reach any food cell. If there is no path for you to reach food, return -1.

- Example:
````bash
        Input: X X X X X X X X
               X P 0 X O F O X
               X O O X O O X X
               X O O O O F O X
               X X X X X X X X
        Output: 3
        Explanation: It takes 3 steps to reach the food.
````

- **Input**:
````bash
        X X X X X X
        X P O O O X
        X O O F O X
        X X X X X X
````

- **Output**:
````bash
        3
````

- [Solution](main.py)

#### Running
- Running a instance:
````bash
    python main.py "path_instance"
````

- Example: running a instance "input1":
````bash
    python main.py instances/input1
````