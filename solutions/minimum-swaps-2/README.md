### [Minimum Swaps 2](https://www.hackerrank.com/challenges/minimum-swaps-2/problem)
- You are given an unordered array consisting of consecutive integers without any duplicates. You are allowed to swap any two elements. You need to find the minimum number of swaps required to sort the array in ascending order.
- For example, given the array arr=[7, 1, 3, 2, 4, 5, 6] we perform the following steps:
````bash
        i   arr                     swap (indices)
        0   [7, 1, 3, 2, 4, 5, 6]   swap (0,3)
        1   [2, 1, 3, 7, 4, 5, 6]   swap (0,1)
        2   [1, 2, 3, 7, 4, 5, 6]   swap (3,4)
        3   [1, 2, 3, 4, 7, 5, 6]   swap (4,5)
        4   [1, 2, 3, 4, 5, 7, 6]   swap (5,6)
        5   [1, 2, 3, 4, 5, 6, 7]
````
- It took 5 swaps to sort the array.

- Instance format:
    - The first line contains an integer n, the size of arr
    - The second line contains n space-separated integers arr[i]


- **Input**:
````bash
        4
        4 3 1 2
````

- **Output**:
````bash
        3
````

- [Solution](main.cpp)

#### Running
- Compiling:
````bash
    source configure.sh
````

- Running an instance:
````bash
    ./app "path_instance"
````

- Example: running an instance "input1":
````bash
    ./app instances/input1
````

### [Back](../../README.md)