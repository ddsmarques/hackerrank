#include <iostream>

int main() {
  int N;
  std::cin >> N;
  int sum = 0;
  for (int i = 0; i < N; i++) {
    int aux;
    std::cin >> aux;
    sum += aux;
  }
  std::cout << sum << std::endl;
}
