# Algorithm Problems

### Fractional Knapsack
- Given weights and values of n items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack. 
- In Fractional Knapsack, we can break items for maximizing the total value of knapsack.
- Develop a solution:
    - O(n log n)
    - O(n)
    - O(n) using partition in sequence with a pivot resulted by:

    ![alt text](knapsack/pivot.png?raw=true)
    
- Instance format:
    - n: number of elements
    - vj: value of j object 
    - wj: weight of j object 
    - c: knapsack's capacity 


- **Input**:
````bash
        n
        1 v1 w1
        2 v2 w2
        ...
        n vn wn
        c
````
- **Output**:
````bash
        Number of items (n)
        Number of items in the knapsack
        Total of Items' Weight in the knapsack
        Total of Items' Value in the knapsack
        
        Time: T
````

- [Solution](knapsack/Knapsack.cpp)
- [Running](knapsack/README.md)
 
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

- [Solution](buildings/build.py)