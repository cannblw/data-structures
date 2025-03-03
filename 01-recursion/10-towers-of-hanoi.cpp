#include <iostream>

// Towers are numbered 1, 2 and 3
constexpr int TOWER_IDX_SUM{1 + 2 + 3};

void towersOfHanoi(int numberOfDisks, int startRod, int endRod) {
  if (numberOfDisks == 1) {
    std::cout << startRod << " -> " << endRod << '\n';
    return;
  }

  /*
   * Because towers are numbered 1, 2 and 3:
   * - If the start rod is 1 and the end rod is 3, the "other" rod is 2 (6 - (1 + 3))
   * - If the start rod is 1 and the end rod is 2, the "other" rod is 3 (6 - (1 + 2))
   * - If the start rod is 3 and the end rod is 2, the "other" rod is 1 (6 - (3 + 2))
   * etc.
   */
  const int otherRod{TOWER_IDX_SUM - (startRod + endRod)};

  towersOfHanoi(numberOfDisks - 1, startRod, endRod);
  std::cout << startRod << " -> " << endRod << '\n';
  towersOfHanoi(numberOfDisks - 1, otherRod, endRod);
}

int main() {
  constexpr int numberOfDisks{3};
  constexpr int startRod{1};
  constexpr int endRod{3};

  towersOfHanoi(numberOfDisks, startRod, endRod);

  return 0;
}
