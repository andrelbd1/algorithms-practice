### 2D Array - DS
- Given 6x6 2D Array, arr:
````bash
        1 1 1 0 0 0
        0 1 0 0 0 0
        1 1 1 0 0 0
        0 0 0 0 0 0
        0 0 0 0 0 0
        0 0 0 0 0 0
````
- An hourglass in A is a subset of values with indices falling in this pattern in arr's graphical representation:
````bash
        a b c
          d
        e f g
````
- There are 16 hourglasses in arr. An hourglass sum is the sum of an hourglass' values. Calculate the hourglass sum for every hourglass in arr, then print the maximum hourglass sum. The array will always be 6x6. Print the largest (maximum) hourglass sum found in arr.

- Example
    - arr =
````bash
        -9 -9 -9  1 1 1 
         0 -9  0  4 3 2
        -9 -9 -9  1 2 3
         0  0  8  6 6 0
         0  0  0 -2 0 0
         0  0  1  2 4 0
````
    - The  hourglass sums are:
````bash
        -63, -34, -9, 12,
        -10,   0, 28, 23,
        -27, -11, -2, 10,
          9,  17, 25, 18
````
    - The highest hourglass sum is 28 from the hourglass beginning at row 1, column 2:
````bash
        0 4 3
          1
        8 6 6
````

- Instance format:
    - Each of the 6 lines of inputs arr[i] contains 6 space-separated integers arr[i][j]. 
    - -9 <= arr[i][j] <= 9
    - 0 <= i,j <= 5

- **Input**:
````bash
        1 1 1 0 0 0
        0 1 0 0 0 0
        1 1 1 0 0 0
        0 0 2 4 4 0
        0 0 0 2 0 0
        0 0 1 2 4 0
````

- **Output**:
````bash
        19
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
