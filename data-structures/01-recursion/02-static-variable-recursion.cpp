#include <iostream>

int recursionWithStaticVar(int n) {
  static int x{0};

  if (n > 0) {
    x++;
    return recursionWithStaticVar(n - 1) + x;
  }

  return 0;
}

int main() {
  constexpr int startValue{5};

  std::cout << recursionWithStaticVar(startValue) << '\n';
  std::cout << recursionWithStaticVar(startValue) << '\n';

  return 0;
}
