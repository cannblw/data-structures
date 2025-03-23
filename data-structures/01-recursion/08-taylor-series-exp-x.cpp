#include <iomanip>
#include <iostream>
#include <limits>

// e^x = 1 + x/1 + x^2/2! + x^3/3!...
double exp(int x, int iterations) {
  static double power{1.0};
  static double factorial{1.0};

  if (iterations == 0) {
    return 1;
  }

  const double ret{exp(x, iterations - 1)};

  power *= x;
  factorial *= iterations;

  return ret + power / factorial;
}

int main() {
  constexpr int exponent{1};
  constexpr int iterations{10};

  std::cout << std::setprecision(std::numeric_limits<double>::digits10) << exp(exponent, iterations) << '\n';

  return 0;
}
