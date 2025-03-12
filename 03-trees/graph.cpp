#include <iostream>
#include <stack>
#include <vector>

class Graph {
  int                           n;
  std::vector<std::vector<int>> adj;

public:
  Graph(int n) : n(n), adj(n) {}

  void add_edge(int a, int b) {
    adj.at(a).push_back(b);
    adj.at(b).push_back(a);
  }

  void display() {
    for (auto n : adj) {

      for (auto nn : n) {
        std::cout << nn << " ";
      }

      std::cout << '\n';
    }
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
  }
};

int main() {
  Graph g = Graph(6);

  g.add_edge(0, 1);
  g.add_edge(0, 2);
  g.add_edge(1, 3);
  g.add_edge(1, 4);
  g.add_edge(2, 5);

  g.display();

  std::cout << '\n';

  g.dfs(0);

  return 0;
}
