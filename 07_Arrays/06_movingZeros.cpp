#include<bits/stdc++.h>
using namespace std;

vector<int> moveZerosToEnd(vector<int> &arr){
  int n = arr.size();
  int j = -1;
  // Finding the first index of 0
  for (int i = 0; i < n; i++) {
    if(arr[i] == 0) {
      j = i;
      break;
    }
  }
  // If there are no 0 element, return the original array
  if (j == -1) return arr;
  // Swapping non-zero elements with j pointer, which stores the index of 0;
  for(int i = j + 1; i < n; i++) {
    if(arr[i] != 0) {
      swap(arr[i], arr[j]);
      j++;
    }
  }
  return arr;
}

int main() {
  vector<int> arr = {1, 0, 2, 3, 4, 0, 0, 5, 6, 7, 0};
  vector<int> result = moveZerosToEnd(arr);
  for (auto it : result) {
    cout << it << " ";
  }
  return 0;
}