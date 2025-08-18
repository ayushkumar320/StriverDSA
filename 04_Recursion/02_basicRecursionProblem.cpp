#include<bits/stdc++.h>
using namespace std;

// 1. Print name n times using recursion
void printName(string name, int n) {
  if (n == 0) return ;    // Base case
  cout << name << endl;
  printName(name, n-1);
}

// Time Complexity - O(n)
// printName() calls itself till n = 0 and when n ==0 the function which called when n = 0 will return and then the above function will also return and this will go till the very first called function.

// 2. Print linearly from 1 to n
void printLinear(int n){
  if (n == 0) return;
  printLinear(n-1);
  cout << n << " ";   // This line gets executed when the last function (n=0) is called and it gets called in bottom to top so 1 2 3 4 5 as last function has n = 1
}
// Its time complexity is O(n)

// 3. Print linearly from n to 1
void printReverse(int n) {
  if (n == 0) return;
  cout << n << " ";   // This line gets executed first and then the function calls itself with n-1 so it prints in order of 5 4 3 2 1
  printReverse(n-1);
}
// Its time complexity is also O(n)



int main() {
  printName("Ayush", 5);
  printLinear(5);
  printReverse(5);
  return 0;
}