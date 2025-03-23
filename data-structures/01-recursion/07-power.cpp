#include <iostream>

int power(int base, int exp) {
  if (exp == 0) {
    return 1;
  }

  if (exp % 2 == 0) {
    return power(base * base, exp / 2);
  }

  return base * power(base * base, (exp - 1) / 2);
}

int main() {
  constexpr int base{2};
  int           exp{8};

  std::cout << power(base, exp) << '\n';

  exp = 9;
  std::cout << power(base, exp) << '\n';

  return 0;
}
