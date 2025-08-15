#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  bool isArmstrong(int n) {
    int original = n;
    int numOfDigit = 0;
    int copyOfn = n;
    while (copyOfn != 0) {
      copyOfn /= 10;
      numOfDigit++;
    }
    int sum = 0;
    while (n != 0) {
      int digit = n % 10;
      sum += (int)pow(digit, numOfDigit);
      n = n / 10;
    }
    return (sum == original);
  }
};