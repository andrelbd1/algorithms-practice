### [Leap Day](https://www.hackerrank.com/challenges/write-a-function/problem)
An extra day is added to the calendar almost every four years as February 29, and the day is called a leap day. It corrects the calendar for the fact that our planet takes approximately 365.25 days to orbit the sun. A leap year contains a leap day.

In the Gregorian calendar, three conditions are used to identify leap years:
- The year can be evenly divided by 4, is a leap year, unless:
    - The year can be evenly divided by 100, it is NOT a leap year, unless:
        - The year is also evenly divisible by 400. Then it is a leap year.

This means that in the Gregorian calendar, the years 2000 and 2400 are leap years, while 1800, 1900, 2100, 2200, 2300 and 2500 are NOT leap years.

- Instance format:
    - The first line contains a single integer, the year.

- **Input**:
````bash
        1990
````

- **Output**:
````bash
        False
````

- Explanation:
    - 1990 is not a multiple of 4 hence it's not a leap year.

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