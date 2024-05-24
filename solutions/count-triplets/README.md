### [Count Triplets](https://www.hackerrank.com/challenges/count-triplets-1/problem)
- You are given an array and you need to find number of tripets of indices (i,j,k) such that the elements at those indices are in geometric progression for a given common ratio r and i<j<k.
- For example, arr=[1,4,16,24]. If r=4, we have [1,4,16] and [4,16,64] at indices (0,1,2) and (1,2,3).

- Instance format:
    - The first line contains two space-separated integers n and r, the size of arr and the common ratio.
    - The next line contains n space-separated integers arr[i].

- **Input**:
````bash
        4 2
        1 2 2 4
````

- **Output**:
````bash
        2
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