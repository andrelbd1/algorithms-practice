### [Array Manipulation](https://www.hackerrank.com/challenges/crush/problem)
- Starting with a 1-indexed array of zeros and a list of operations, for each operation add a value to each the array element between two given indices, inclusive. Once all operations have been performed, return the maximum value in the array.
- Example

````bash
        n = 10
        queries = [[1,5,3],[4,8,7],[6,9,1]]
````

- Queries are interpreted as follows:
````bash
        a b k
        1 5 3
        4 8 7
        6 9 1
````

- Add the values of k between the indices a and b inclusive:
````bash
index->	 1 2 3  4  5 6 7 8 9 10
        [0,0,0, 0, 0,0,0,0,0, 0]
        [3,3,3, 3, 3,0,0,0,0, 0]
        [3,3,3,10,10,7,7,7,0, 0]
        [3,3,3,10,10,8,8,8,1, 0]
````
- The largest value is 10 after all operations are performed.

- Instance format:
    - The first line contains two space-separated integers n and m, the size of the array and the number of operations.
    - Each of the next m lines contains three space-separated integers a, b and k, the left index, right index and summand.

- **Input**:
````bash
        5 3
        1 2 100
        2 5 100
        3 4 100
````

- **Output**:
````bash
        200
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
