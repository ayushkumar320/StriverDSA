#include<bits/stdc++.h>
using namespace std;

vector<int> rotateArrayByOne(vector<int> &arr) {
  int n = arr.size();
  int temp = arr[0];
  for(int i = 1; i < n; i++) {
    arr[i-1] = arr[i];
  }
  arr[n-1] = temp;
  return arr;
}

int main() {
  vector<int> arr = {1, 2, 3, 4 ,5};
  vector<int> rotatedArray = rotateArrayByOne(arr);
  for(auto it = rotatedArray.begin(); it != rotatedArray.end(); it++) {
    cout << *it << " ";
  }
  return 0;
}