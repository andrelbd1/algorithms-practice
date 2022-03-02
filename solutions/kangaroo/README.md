### [Kangaroo](https://www.hackerrank.com/challenges/kangaroo/problem)
You are choreographing a circus show with various animals. For one act, you are given two kangaroos on a number line ready to jump in the positive direction (i.e, toward positive infinity).
- The first kangaroo starts at location x1 and moves at a rate of v1 meters per jump.
- The second kangaroo starts at location x2 and moves at a rate of v2 meters per jump.

You have to figure out a way to get both kangaroos at the same location at the same time as part of the show. If it is possible, return YES, otherwise return NO.


- Example:
````bash
        2 1 1 2
````
    - After one jump, they are both at x = 3, so the answer is YES.

- Instance format:
    - A single line of four space-separated integers denoting the respective values of x1, v1, x2, and v2.

- **Input**:
````bash
        0 3 4 2
````

- **Output**:
````bash
        YES
````

- Explanation:
    - The two kangaroos jump through the following sequence of locations. The kangaroos meet at the same location (number 12 on the number line) after same number of jumps (4 jumps), and we print YES.

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
