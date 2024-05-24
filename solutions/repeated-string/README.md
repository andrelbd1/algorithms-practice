### [Repeated String](https://www.hackerrank.com/challenges/repeated-string/problem)
- There is a string, s, of lowercase English letters that is repeated infinitely many times. Given an integer, n, find and print the number of letter a's in the first n letters of the infinite string.  Return the frequency of a in the substring.

- Example
    - s = 'abcac'
    - n = 10
    - The substring we consider is abcacabcac, the first 10 characters of the infinite string. There are 4 occurrences of a in the substring.

- Instance format:
    - The first line contains a single string, s.
    - The second line contains an integer, n.

- **Input**:
````bash
        aba
        10
````

- **Output**:
````bash
        7
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