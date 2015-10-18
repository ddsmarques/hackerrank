#include <cstdio>

int main() {
  char s[11];
  scanf(" %s", s);
  int hh = (s[0] - '0')*10 + (s[1] - '0');
  int mm = (s[3] - '0')*10 + (s[4] - '0');
  int ss = (s[6] - '0')*10 + (s[7] - '0');

  if (s[8] == 'A') {
    if (hh == 12) {
      hh = 0;
    }
  } else {
    if (hh != 12) {
      hh += 12;
    }
  }
  printf("%02d:%02d:%02d\n", hh, mm, ss);
  return 0;
}
