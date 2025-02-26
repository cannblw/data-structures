#include <iostream>

int nestedRecursion(int n) {
  if (n > 100) {
    return n - 10;
  } else {
    return nestedRecursion(nestedRecursion(n + 11));
  }

  nestedRecursion(n - 1);
}

int main() {
  constexpr int startValue{95};

  std::cout << nestedRecursion(startValue) << '\n';

  return 0;
}
