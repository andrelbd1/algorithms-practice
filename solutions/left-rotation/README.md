### [Left Rotation](https://www.hackerrank.com/challenges/ctci-array-left-rotation/problem)
- A left rotation operation on an array shifts each of the array's elements 1 unit to the left. For example, if 2 left rotations are performed on array [1, 2, 3, 4, 5], then the array would become [3, 4, 5, 1, 2]. Note that the lowest index item moves to the highest index in a rotation. This is called a circular array.
- Given an array a of n integers and a number, d, perform d left rotations on the array. Return the updated array to be printed as a single line of space-separated integers.

- Instance format:
    - The first line contains two space-separated integers n and d, the size of a and the number of left rotations.
    - The second line contains n space-separated integers, each an a[i].

- **Input**:
````bash
        5 4
        1 2 3 4 5
````

- **Output**:
````bash
        5 1 2 3 4
````

- [Solution](main.cpp)

#### Running
- Compiling:
````bash
    source configure.sh
````

- Running a instance:
````bash
    ./app "path_instance"
````

- Example: running a instance "input1":
````bash
    ./app instances/input1
````
