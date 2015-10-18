#include <cstdio>
#include <cstdlib>

int main() {
  int N;
  int sum1 = 0;
  int sum2 = 0;
  scanf(" %d", &N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int aux;
      scanf(" %d", &aux);
      if (i == j) {
        sum1 += aux;
      }
      if (i + j == N-1) {
        sum2 += aux;
      }
    }
  }
  printf("%d\n", std::abs(sum1 - sum2));
  return 0;
}

