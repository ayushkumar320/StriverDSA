#include<bits/stdc++.h>
using namespace std;

int main() {
  
  // For loop

  for(int i = 0; i < 10; i++) {
    cout << i << " ";
  }
  cout << endl;

  // While loop
  int i = 0;
  while (i < 10) {
    cout << i << " ";
    i++;
  }
  cout << endl;

  // For each loop

  int arr[] = {1, 2, 3, 4, 5};
  cout << "For each loop: ";
  for (int x : arr) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}