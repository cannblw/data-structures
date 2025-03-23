#include <iostream>

int factorial(int n) {
  if (n == 0) {
    return 1;
  }

  return factorial(n - 1) * n;
}

int main() {
  constexpr int n{5};

  std::cout << factorial(n) << '\n';

  return 0;
}
