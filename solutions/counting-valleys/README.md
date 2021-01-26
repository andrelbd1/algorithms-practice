### [Counting Valleys](https://www.hackerrank.com/challenges/counting-valleys/problem)
- An avid hiker keeps meticulous records of their hikes. During the last hike that took exactly  steps, for every step it was noted if it was an uphill, U, or a downhill, D step. Hikes always start and end at sea level, and each step up or down represents a 1 unit change in altitude. We define the following terms:
	- A mountain is a sequence of consecutive steps above sea level, starting with a step up from sea level and ending with a step down to sea level.
	- A valley is a sequence of consecutive steps below sea level, starting with a step down from sea level and ending with a step up to sea level.

- Given the sequence of up and down steps during a hike, find and print the number of valleys walked through.

- Instance format:
    - The first line contains an integer n, the number of steps on the hike.
    - The second line contains string describing the path

- **Input**:
````bash
        8
        UDDDUDUU        
````

- **Output**:
````bash
        1
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
