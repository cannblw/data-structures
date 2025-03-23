#include <iostream>
#include <queue>
#include <vector>

class Graph {
  int                           n;
  std::vector<std::vector<int>> adj;

public:
  Graph(int nodes) : n(nodes), adj(nodes) {}

  void add_edge(int u, int v) {
    adj.at(u).push_back(v);
    adj.at(v).push_back(u);
  }

  void bfs(int start) {
    std::vector<bool> visited(n, false);
    std::queue<int>   q;

    visited.at(start) = true;
    q.push(start);

    while (!q.empty()) {
      int node = q.front();
      q.pop();

      std::cout << node << ' ';

      for (int neighbor : adj.at(node)) {
        if (!visited.at(neighbor)) {
          visited.at(neighbor) = true;
          q.push(neighbor);
        }
      }
    }

    std::cout << '\n';
  }

  void dfs(int start) {
    std::vector<bool> visited(n, false);
    std::stack<int>   s;

    visited.at(start) = true;
    s.push(start);

    while (!s.empty()) {
      int node = s.top();
      s.pop();

      std::cout << node << ' ';

      for (auto it = adj.at(node).rbegin(); it != adj.at(node).rend(); ++it) {
        if (!visited.at(*it)) {
          visited.at(*it) = true;
          s.push(*it);
        }
      }
    }

    std::cout << '\n';
  }
};

int main() {
  Graph g(6);

  g.add_edge(0, 1);
  g.add_edge(0, 2);
  g.add_edge(1, 3);
  g.add_edge(1, 4);
  g.add_edge(2, 5);

  std::cout << "BFS: ";
  g.bfs(0);

  std::cout << "DFS: ";
  g.dfs(0);
}
