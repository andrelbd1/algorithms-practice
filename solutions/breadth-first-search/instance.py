from bfs import BreadthFirstSearch as BFS

graph = {
   "a" : ["b","c"],
   "b" : ["a","d"],
   "c" : ["a","d"],
   "d" : ["e"],
   "e" : ["d"],
   "f" : ["g"],
   "g" : ["f"]
}

print('Graph: ', graph)

instance = BFS(graph)

assert instance.bfs(root="a",value="e") == "e"
assert instance.bfs(root="b",value="c") == "c"
assert instance.bfs(root="a",value="f") == -1
assert instance.bfs(root="a",value="g") == -1