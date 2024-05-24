### [Jumping on the Clouds](https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem)
- There is a new mobile game that starts with consecutively numbered clouds. Some of the clouds are thunderheads and others are cumulus. The player can jump on any cumulus cloud having a number that is equal to the number of the current cloud plus 1 or 2. The player must avoid the thunderheads. Determine the minimum number of jumps it will take to jump from the starting postion to the last cloud. It is always possible to win the game. For each game, you will get an array of clouds numbered 0 if they are safe or 1 if they must be avoided. Return the minimum number of jumps required.

- Example
    - c = [0,1,0,0,0,1,0] 
    - Index the array from 0...6. The number on each cloud is its index in the list so the player must avoid the clouds at indices 1 and 5.
    - They could follow these two paths: 0 -> 2 -> 4 -> 6 or 0 -> 2 -> 3 -> 4 -> 6. The first path takes 3 jumps while the second takes 4. Return 3.

- Instance format:
    - The first line contains an integer n, the number of clouds.
    - The second line contains n space-separated binary integers describing clouds c[i] where 0 <= i <= n.

- **Input**:
````bash
        7
        0010010
````

- **Output**:
````bash
        4
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