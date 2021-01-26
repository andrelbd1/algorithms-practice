### [Frequency Queries](https://www.hackerrank.com/challenges/frequency-queries/problem)
- You are given q queries. Each query is of the form two integers described below:
    - 1 x: Insert x in your data structure.
    - 2 y: Delete one occurence of y from your data structure, if present.
    - 3 z: Check if any integer is present whose frequency is exactly z. If yes, print 1 else 0.

- The queries are given in the form of a 2-D array queries of size q where queries[i][0] contains the operation, and queries[i][1] contains the data element. For example, you are given array queries=[(1,1),(2,2),(3,2),(1,1),(1,1),(2,1),(3,2)]. The results of each operation are:

````bash
        Operation   Array   Output
        (1,1)       [1]
        (2,2)       [1]
        (3,2)                   0
        (1,1)       [1,1]
        (1,1)       [1,1,1]
        (2,1)       [1,1]
        (3,2)                   1
````
    - Return an array with the output: [0,1]

- Instance format:
    - The first line contains an integer q, the number of queries.
    - Each of the next q lines contains two integers denoting the 2-d array queries.

- **Input**:
````bash
        8
        1 5
        1 6
        3 2
        1 10
        1 10
        1 6
        2 5
        3 2
````

- **Output**:
````bash
        0
        1
````

- Explanation:
    - For the first query of type 3, there is no integer whose frequency is 2 (array=[5,6]). So answer is 0.
    - For the second query of type 3, there are two integers in array=[6,10,10,6] whose frequency is 2 (integers=6 and 10). So, the answer is 1.

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
