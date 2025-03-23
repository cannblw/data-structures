#include <iostream>

class Array {
  int* A;
  int  size;
  int  length;

public:
  Array(const int items[], int size, int length) : size(size), length(length) {
    A = new int[size];

    for (int i = 0; i < length; ++i) {
      A[i] = items[i];
    }
  }

  ~Array() { delete[] A; }

  void display() {
    std::cout << "Elements are: ";

    for (int i{0}; i < length; ++i) {
      std::cout << A[i] << ' ';
    }
  }
};

int main() {
  constexpr int items[]{2, 3, 4, 5, 6};
  constexpr int size{20};
  constexpr int length{5};

  Array a = Array(items, size, length);

  a.display();

  return 0;
}
