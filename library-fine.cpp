#include <cstdio>

int main() {
  int D1, M1, Y1;
  int D2, M2, Y2;
  scanf(" %d %d %d", &D1, &M1, &Y1);
  scanf(" %d %d %d", &D2, &M2, &Y2);
  if ((Y1 < Y2) || (Y1 == Y2 && M1 < M2) || (Y1 == Y2 && M1 == M2 && D1 <= D2)) {
    printf("0\n");
  } else if ((Y1 == Y2 && M1 == M2)) {
    printf("%d\n", 15 * (D1 - D2));
  } else if (Y1 == Y2) {
    printf("%d\n", 500 * (M1 - M2));
  } else {
    printf("10000\n");
  }
  return 0;
}
