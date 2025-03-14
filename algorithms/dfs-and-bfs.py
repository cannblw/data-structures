from collections import deque


class Graph:
    def __init__(self, n):
        self.adj = [[]] * n

    def add_edge(self, a, b):
        self.adj[a].append(b)
        self.adj[b].append(a)

    def dfs(self, start):
        visited, stack = set(), [start]
        while stack:
            node = stack.pop()
            if node not in visited:
                print(node, end=" ")
                visited.add(node)
                for neighbor in reversed(self.adj[node]):
                    stack.append(neighbor)

    def bfs(self, start):
        visited, queue = set(), deque([start])
        while queue:
            node = queue.popleft()
            if node not in visited:
                print(node, end=" ")
                visited.add(node)
                for neighbor in self.adj[node]:
                    queue.append(neighbor)


graph = Graph(5)
graph.add_edge(0, 1)
graph.add_edge(0, 2)
graph.add_edge(1, 3)
graph.add_edge(2, 4)

# Run DFS and BFS from node 0
print("DFS from node 0:")
graph.dfs(0)

print("\nBFS from node 0:")
graph.bfs(0)
