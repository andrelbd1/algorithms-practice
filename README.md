# Algorithm Problems and Solutions
- List of algorithm problems and solutions using C, C++ and Python.

### [Fractional Knapsack](solutions/knapsack/README.md)

### [Polynomial Multiplication](solutions/polynomial-multiplication/README.md)

### Interval Scheduling
- Given a set of lectures L={l1, ... ln } such that each lecture is defined by its start time and duration. The goal is present maximum number of lectures without any interval conflict.

- **Input**:
````bash
        [start 1, ... start n] [duration 1, ... duration n]
````

- **Output**:
````bash
        max_lectures
````

- [Solution](solutions/interval-scheduling/code.py)

### Shortest Path for Buildings
- Given a grid with w as width, h as height. Each cell of the grid represents a potential building lot and we will be adding "n" buildings inside this grid. The goal is for the furthest of all lots to be as near as possible to a building. Given an input n, which is the number of buildings to be placed in the lot, determine the building placement to minimize the distance the most distant empty lot is from the building. Movement is restricted to horizontal and vertical i.e. diagonal movement is not required.
- For example, w=4, h=4 and n=3. An optimal grid placement sets any lot within two unit distance of the building. The answer for this case is 2.
- "0" indicates optimal building placement and in this case the maximal value of all shortest distances to the closest building for each cell is "2".
- Example:

````bash
        1 0 1 2
        2 1 2 1
        1 0 1 0
        2 1 2 1
````

- **Input**:
````bash
        w h n
````

- **Output**:
````bash
        max_value
````

- [Solution](solutions/buildings/build.py)