#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isPalindrome(int n) {
      int original = n;
      if (n<0) return false;
      int reversed = 0;
      while(n!=0){
        int digit = n%10;
        reversed = reversed*10 + digit;
        n = n/10;
      }
      if(reversed == original){
        return true;
      } else {
        return false;
      }
    }
};