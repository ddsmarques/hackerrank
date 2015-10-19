#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

class BigInteger {
 public:
  string num;

  BigInteger() {
  }

  BigInteger(int n) {
    string aux = std::to_string(n);
    num = "";
    for (int i = aux.size()-1; i >= 0; i--) {
      //printf("debug %d %c\n", i, aux[i]);
      num += aux[i];
    }
  }
  void addLeadingZeros(int zeros) {
    for (int i = 0; i < zeros; i++) {
      num += "0";
    }
  }

  void shiftLeft(int shift) {
    int lastDigit = num.size() - 1;
    addLeadingZeros(shift);
    for (int i = lastDigit; i >= 0; i--) {
      num[num.size() - 1 - (lastDigit - i)] = num[i];
    }
    for (int i = 0; i < shift; i++) {
      num[i] = '0';
    }
  }

  void print() {
    string aux = num;
    reverse(aux.begin(), aux.end());
    bool diffZero = false;
    for (int i = 0; i < aux.size()-1; i++) {
      if (aux[i] != '0') {
        diffZero = true;
      }
      if (diffZero) {
        printf("%c", aux[i]);
      }
    }
    if (aux.size() > 0) {
      printf("%c\n", aux[aux.size()-1]);
    }
  }
};

BigInteger operator+(const BigInteger& a, const BigInteger& b) {
  BigInteger first = a;
  BigInteger second = b;
  if (first.num.size() > second.num.size()) {
    second.addLeadingZeros(first.num.size() - second.num.size());
  } else if (second.num.size() > first.num.size()) {
    first.addLeadingZeros(second.num.size() - first.num.size());
  }
  BigInteger ans;
  int carry = 0;
  for (int i = 0; i < first.num.size(); i++) {
    int aux = (first.num[i] - '0') + (second.num[i] - '0') + carry;
    carry = aux/10;
    ans.num += (char)((aux%10) + '0');
  }
  ans.num += (char)(carry + '0');
  //return std::move(ans);
  return ans;
}

BigInteger multOneDigit(const BigInteger& a, char c) {
  int n = c - '0';
  BigInteger ans;
  int carry = 0;
  for (int i = 0; i < a.num.size(); i++) {
    int aux = (a.num[i] - '0') * n + carry;
    carry = aux/10;
    ans.num += (char)((aux%10) + '0');
  }
  ans.num += (char)(carry + '0');
  //return std::move(ans);
  return ans;
}

BigInteger operator*(const BigInteger& a, const BigInteger& b) {
  BigInteger ans(0);
  for (int i = 0; i < a.num.size(); i++) {
    BigInteger aux = multOneDigit(b, a.num[i]);
    aux.shiftLeft(i);
    //aux.print();
    ans = ans + aux;
  }
  //return std::move(ans);
  return ans;
}

int main() {
  int N;
  scanf(" %d", &N);
  BigInteger ans(1);
  for (int i = 1; i <= N; i++) {
    BigInteger aux(i);
    //aux.print();
    ans = ans * aux;
    //ans.print();
  }
  ans.print();
  return 0;
}

