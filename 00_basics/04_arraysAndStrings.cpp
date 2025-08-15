#include<bits/stdc++.h>
using namespace std;

int main(){
  // Arrays
  int arr[5] = {1, 2, 3, 4, 5};
  cout << "Array elements: ";
  for (int i = 0; i < 5; i++) {
    cout << arr[i] << " ";
  }

  // We can modify them as well
  arr[0] = 10;
  arr[1] = 20;
  arr[2] = 30;
  arr[3] = 40;
  arr[4] = 50;
  cout << "Modified array elements: ";
  for (int i = 0; i < 5; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  // Strings - Array of characters
  string str = "Hello, World!";
  cout << "String: " << str << endl;
  cout << str[2] << endl;
  int len = str.length();
  cout << str[len-1] << endl;
  str[len - 1] = '?';
  cout << "Modified string: " << str << endl;

  return 0;
}