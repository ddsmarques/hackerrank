#include <cstdio>
#include <cmath>

int main() {
  int N;
  int neg = 0;
  int pos = 0;
  int zero = 0;
  scanf(" %d", &N);
  for (int i = 0; i < N; i++) {
    int aux;
    scanf(" %d", &aux);
    if (aux < 0) {
      neg++;
    } else if (aux == 0) {
      zero++;
    } else {
      pos++;
    }
  }
  printf("%.3f\n", ((1000 * pos)/N)/1000.0);
  printf("%.3f\n", ((1000 * neg)/N)/1000.0);
  printf("%.3f\n", ((1000 * zero)/N)/1000.0);
  return 0;
}

