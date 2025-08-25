#include<bits/stdc++.h>
using namespace std;

// Runtime error :)
int countDigitOne(int n) {
  int count = 0;
  for(int i = 1; i <= n; i++) {
    int num = i;
    while(num > 0) {
      if(num % 10 == 1) {
        count++;
      }
      num /= 10;
    }
  }
  return count;
}

int main() {
  int n;
  cout << "Enter a number: ";
  cin >> n;
  cout << "Number of digit '1's from 1 to " << n << " is: " << countDigitOne(n) << endl;
  return 0;
}