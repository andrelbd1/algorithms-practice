- Compiling:
````bash
    source configure.sh
````

- Running a instance:
````bash
    ./Knapsack "path_instance" "complexity_selected"
````

- Example: running a instance "knap_1000_1.in" using  O(n log n) solution:
````bash
    ./Knapsack instances/knap_1000_1.in 1
````

- Example: running a instance "knap_1000_1.in" using  O(n) solution:
````bash
    ./Knapsack instances/knap_1000_1.in 2
````

- Example: running a instance "knap_1000_1.in" using  O(n) using partition solution:
````bash
    ./Knapsack instances/knap_1000_1.in 3
````