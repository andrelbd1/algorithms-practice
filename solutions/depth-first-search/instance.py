from dfs import DepthFirstSearch as DFS

graph = {
   "a" : ["b","c"],
   "b" : ["a", "d"],
   "c" : ["a", "d"],
   "d" : ["e"],
   "e" : ["d"],
   "f" : ["g"],
   "g" : ["f"]
}

print('Graph: ', graph)

instance = DFS(graph)

assert instance.dfs(root="a",value="e") == "e"
assert instance.dfs(root="b",value="c") == "c"
assert instance.dfs(root="a",value="f") == -1
assert instance.dfs(root="a",value="g") == -1