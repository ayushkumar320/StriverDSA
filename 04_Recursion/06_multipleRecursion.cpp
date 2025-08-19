#include<bits/stdc++.h>
using namespace std;

// Multiple Recursion:

// Multiple recursion is a type of recursion where a function makes multiple recursive calls to itself. This can lead to a tree-like structure of function calls, where each call can branch into several more calls. It's often used in problems that can be divided into smaller subproblems, each of which can be solved independently.

// Fibbonacci Series
int fibb(int n) {
  if (n <= 1) return n;
  return fibb(n - 1) + fibb(n - 2);   // Multiple recursion
}

int main() {
  int n = 10; 
  cout << "Fibonacci of " << n << " is " << fibb(n) << endl;
  return 0;
}