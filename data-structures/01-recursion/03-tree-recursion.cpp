#include <iostream>

void treeRecursion(int n) {
  if (n > 0) {
    std::cout << n << '\n';

    treeRecursion(n - 1);
    treeRecursion(n - 1);
  }
}

int main() {
  constexpr int startValue{3};

  treeRecursion(startValue);

  return 0;
}
