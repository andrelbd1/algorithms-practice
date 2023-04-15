### [Two Strings](https://www.hackerrank.com/challenges/two-strings/problem)
- Given two strings, determine if they share a common substring. A substring may be as small as one character.

- Example:
````bash
        s1='and'
        s2='art'
````
    - These share the common substring a.

````bash
        s1='be'
        s2='cat'
````
    - These do not share a substring.

- Instance format:
    - The first line contains a single integer p, the number of test cases.
    - The following p pairs of lines are as follows:
        - The first line contains string s1.
        - The second line contains string s2.

- **Input**:
````bash
        2
        hello
        world
        hi
        world
````

- **Output**:
````bash
        YES
        NO
````

- [Solution](main.py)

#### Running
- Running an instance:
````bash
    python main.py "path_instance"
````

- Example: running an instance "input1":
````bash
    python main.py instances/input1
````