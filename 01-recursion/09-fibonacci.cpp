#include <chrono>
#include <iostream>

int fibonacci(int n) {
  if (n <= 1) {
    return n;
  }

  return fibonacci(n - 2) + fibonacci(n - 1);
}

int fibonacciWithMemoization(int n, std::vector<int>& memo) {
  if (n <= 1) {
    return n;
  }

  if (memo[n] != -1)
    return memo[n];

  memo[n] = fibonacciWithMemoization(n - 1, memo) + fibonacciWithMemoization(n - 2, memo);

  return memo[n];
}

int main() {
  // 50th term
  constexpr int term{40};

  auto start{std::chrono::high_resolution_clock::now()};
  int  result{fibonacci(term)};
  auto end{std::chrono::high_resolution_clock::now()};

  auto duration{std::chrono::duration_cast<std::chrono::milliseconds>(end - start)};

  std::cout << "Without memoization: " << duration.count() << " ms. Result: " << result << '\n';

  std::vector<int> memo(term + 1, -1);
  start = std::chrono::high_resolution_clock::now();
  result = fibonacciWithMemoization(term, memo) << '\n';
  end = std::chrono::high_resolution_clock::now();

  duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

  std::cout << "With memoization: " << duration.count() << " ms. Result: " << result << '\n';

  return 0;
}
