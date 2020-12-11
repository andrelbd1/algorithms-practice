### Fractional Knapsack
- Given weights and values of n items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
- In Fractional Knapsack, we can break items for maximizing the total value of knapsack.
- Develop a solution:
    - O(n log n)
    - O(n)
    - O(n) using partition in sequence with a pivot resulted by:

    ![alt text](pivot.png?raw=true)

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

- [Solution](Knapsack.cpp)

#### Running
- Compiling:
````bash
    source configure.sh
````

- Running a instance:
````bash
    ./Knapsack "path_instance" "complexity_selected"
````

- Example: running a instance "knap_1000_1.in" using  O(n log n) solution:
````bash
    ./Knapsack instances/knap_1000_1.in 1
````

- Example: running a instance "knap_1000_1.in" using  O(n) solution:
````bash
    ./Knapsack instances/knap_1000_1.in 2
````

- Example: running a instance "knap_1000_1.in" using  O(n) using partition solution:
````bash
    ./Knapsack instances/knap_1000_1.in 3
````