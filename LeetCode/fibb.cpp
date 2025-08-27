#include<bits/stdc++.h>
using namespace std;

int fibb(int n, vector<int>& hash) {
  // Base case
  if (n < 2) return n;
  if (hash[n] != 0) return hash[n];
  hash[n] = fibb(n-1, hash) + fibb(n-2, hash);
  return hash[n];
}

int fib (int n) {
  vector<int> hash(n+1, 0);
  return fibb(n, hash);
}


int main() {
  int n = 8;
  cout << fib(n);
  return 0;
}