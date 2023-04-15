### [Sales by Match](https://www.hackerrank.com/challenges/sock-merchant/problem)
- Alex works at a clothing store. There is a large pile of socks that must be paired by color for sale. Given an array of integers representing the color of each sock, determine how many pairs of socks with matching colors there are. For example, there are n = 7 socks with colors ar = [1,2,1,2,1,3,2]. There is one pair of color 1 and one of color 2 There are three odd socks left, one of each color. The number of pairs is 2.

- Instance format:
    - The first line contains an integer n, the number of socks represented in ar
    - The second line contains n space-separated integers describing the colors ar[i] of the socks in the pile
    - n: the number of socks in the pile
    - ar: the colors of each sock


- **Input**:
````bash
        n
        i0 i1 ... in        
````

- **Output**:
````bash
        result
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
