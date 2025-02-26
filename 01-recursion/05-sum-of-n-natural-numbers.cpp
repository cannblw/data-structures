#include <iostream>

int sumOfNNaturalNumbers(int n) {
  if (n == 0) {
    return 0;
  }

  return sumOfNNaturalNumbers(n - 1) + n;
}

int main() {
  constexpr int n{5};

  std::cout << sumOfNNaturalNumbers(n) << '\n';

  return 0;
}
