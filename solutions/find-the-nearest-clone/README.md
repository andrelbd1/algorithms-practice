### [Find the Nearest Clone](https://www.hackerrank.com/challenges/find-the-nearest-clone/problem)
- In this challenge, there is a connected undirected graph where each of the nodes is a color. Given a color, find the shortest path connecting any two nodes of that color. Each edge has a weight of 1. If there is not a pair or if the color is not found, print -1.

- For example, given `graph_nodes = 5`, and 4 edges `graph_from = [1,2,2,3]` and `graph_to = [2,3,4,5]` and colors for each node are `ids = [1,2,3,1,3]`. Each of the nodes is labeled [node]/[color] and is colored appropriately.
    - If we want the shortest path between color 3, we see there is a direct path between nodes 3 and 5.
    - For color 1, we see the path length 2 from 1 -> 2 -> 4.

graph_nodes, graph_from, graph_to, ids, val

- Function Params Description
    - g_nodes: an integer, the number of nodes
    - g_from: an array of integers, the start nodes for each edge
    - g_to: an array of integers, the end nodes for each edge
    - ids: an array of integers, the color id per node
    - val: an integer, the id of the color to match

- [Solution](main.py)

### [Back](../../README.md)