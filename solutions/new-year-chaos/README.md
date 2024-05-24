### [New Year Chaos](https://www.hackerrank.com/challenges/new-year-chaos/problem)
- It is New Year's Day and people are in line for the Wonderland rollercoaster ride. Each person wears a sticker indicating their initial position in the queue. Initial positions increment by 1 from 1 at the front of the line to n at the back.
- Any person in the queue can bribe the person directly in front of them to swap positions. If two people swap positions, they still wear the same sticker denoting their original places in line. One person can bribe at most two others. For example, if n=8 and Person 5 bribes Person 4, the queue will look like this: 1, 2, 3, 5, 4, 6, 7, 8. 
- Fascinated by this chaotic queue, you decide you must know the minimum number of bribes that took place to get the queue into its current state. If anyone has bribed more than two people, the line is too chaotic to compute the answer.
- No value is returned. Print the minimum number of bribes necessary or Too chaotic if someone has bribed more than 2 people.

- Instance format:
    - The first line contains an integer t, the number of test cases.
    - Each of the next t pairs of lines are as follows:
        - The first line contains an integer t, the number of people in the queue
        - The second line has n space-separated integers describing the final state of the queue.

- **Input**:
````bash
        2
        5
        2 1 5 3 4
        5
        2 5 1 3 4
````

- **Output**:
````bash
        3
        Too chaotic
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