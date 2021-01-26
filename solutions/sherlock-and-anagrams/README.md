### [Sherlock and Anagrams](https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem)
- Two strings are anagrams of each other if the letters of one string can be rearranged to form the other string. Given a string, find the number of pairs of substrings of the string that are anagrams of each other.

- Example:
````bash
        s='mom'
````
    - The list of all anagrammatic pairs is [m, m], [mo, om] at positions [[0],[2]], [[0,1],[1,2]] respectively.

- Instance format:
    - The first line contains a single integer q, the number of queries.
    - Each of the next q lines contains a string s to analyze.

- **Input**:
````bash
        2
        abba
        abcd
        ifailuhkqq
        kkkk
        cdcd
````

- **Output**:
````bash
        4
        0
        3
        10
        5
````

- Explanation:
    - For the first query, the list of all anagrammatic pairs is [a, a], [ab, ba], [b, b], [abb, bba].
    - The second one has no anagrammatic pairs exist in the second query as no character repeats.
    - For the third query, we have anagram pairs [i,i], [q,q] and [ifa, fai].
    - For the fourth query: 
        - There are 6 anagrams of the form [k, k] at positions [[0],[1]], [[0],[2]], [[0],[3]], [[1],[2]], [[1],[3]] and [[2],[3]].
        - There are 3 anagrams of the form [kk, kk] at positions [[0, 1], [1, 2]], [[0, 1], [2, 3]] and [[1, 2], [2, 3]].
        - There is 1 anagram of the form [kkk, kkk] at positions [[0, 1, 2], [1, 2, 3]].
    - In the fifth query:
        - There are two anagrammatic pairs of length 1: [c, c] and [d, d].
        - There are three anagrammatic pairs of length 2: [cd, dc], [cd, cd] and [dc, cd].

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
