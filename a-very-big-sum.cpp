#include <iostream>

int main() {
  int N;
  std::cin >> N;
  long long sum = 0;
  for (int i = 0; i < N; i++) {
    int aux;
    std::cin >> aux;
    sum += aux;
  }
  std::cout << sum << std::endl;
  return 0;
}
