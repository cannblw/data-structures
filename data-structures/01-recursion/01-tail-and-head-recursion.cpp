#include <iostream>

void tailRecursion(int n) {
  if (n > 0) {
    std::cout << n << '\n';
    tailRecursion(n - 1);
  }
}

void headRecursion(int n) {
  if (n > 0) {
    headRecursion(n - 1);
    std::cout << n << '\n';
  }
}

int main() {
  constexpr int startValue{3};

  tailRecursion(startValue);
  std::cout << '\n';
  headRecursion(startValue);

  return 0;
}
