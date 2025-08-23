#include<bits/stdc++.h>
using namespace std;

vector<int> bruteForceRotate(vector<int> arr, int d) {
  int n = arr.size();
  d = d % n;
  vector<int> temp;
  for(int i = 0; i < d; i++) {
    temp.push_back(arr[i]);
  }
  for(int i = d; i < n; i++){
    arr[i-d] = arr[i];
  }
  // Placing back the temp
  for(int i = n - d; i < n; i++){
    arr[i] = temp[i - (n - d)];
  }
  return arr;
}

void leftRotate(vector<int>& arr, int d) {
  int n = arr.size();
  d = d % n;  // To wrap around the rotations if needed
  reverse(arr.begin(), arr.begin() + d);
  reverse(arr.begin() + d, arr.end());
  reverse(arr.begin(), arr.end());
}

void rightRotate(vector<int> &arr, int d) {
  int n = arr.size();
  d = d % n;  // To wrap around the rotations if needed
  // First we will reverse the whole array
  reverse(arr.begin(), arr.end());
  // After that we will reverse the first d elements
  reverse(arr.begin(), arr.begin() + d);
  // Finally, we will reverse the remaining elements
  reverse(arr.begin() + d, arr.end());
}

int main() {
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
  // vector<int> rotated = bruteForceRotate(arr, 3);
  leftRotate(arr, 3);
  for (auto it : arr) {
    cout << it << " ";
  }
  return 0;
}