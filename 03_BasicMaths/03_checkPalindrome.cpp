#include<bits/stdc++.h>
using namespace std;

bool checkPalindrome(int original, int reverse){
  return original == reverse;
}

int reverseNum(int n){
  int rev = 0;
  while(n > 0){
    int ld = n % 10;
    rev = rev * 10 + ld;
    n = n / 10;
  }
  return rev;
}

int main(){
  int num;
  cout << "Enter a number: ";
  cin >> num;

  int reversed = reverseNum(num);
  if(checkPalindrome(num, reversed)){
    cout << num << " is a palindrome." << endl;
  } else {
    cout << num << " is not a palindrome." << endl;
  }
  return 0;
}