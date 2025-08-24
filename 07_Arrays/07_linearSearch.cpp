#include<bits/stdc++.h>
using namespace std;

int linearSearch(vector<int> arr, int key) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    if(arr[i] == key) {
      return i;
    }
  }
  return -1;
}

int main() {
  vector<int> arr = {1, 2, 3, 4, 5};
  int key = 3;
  int index = linearSearch(arr, key);
  if (index != -1) {
    cout << "Element found at index: " << index << endl;
  } else {
    cout << "Element not found" << endl;
  }
  return 0;
}