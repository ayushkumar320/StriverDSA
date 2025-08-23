#include<bits/stdc++.h>
using namespace std;

int bruteForceWay(vector<int> &arr) {
  set<int> st;
  for(int i = 0; i < arr.size(); i++) {
    st.insert(arr[i]);  // set does not allow duplication
  }
  int index = 0;
  for (auto it : st) {
    arr[index] = it;
    index++;
  }
  return index;
}

int optimalWay(vector<int> &arr) {
  int i = 0;
  for(int j = 1; j < arr.size(); j++) {
    if(arr[i] != arr[j]) {
      arr[i+1] = arr[j];
      i++;
    }
  }
  // i will point to the last unique element index
  return i + 1;
}

int main() {
  vector<int> arr = {1, 2, 2, 3, 4, 4, 5};
  int newSize = optimalWay(arr);
  cout << newSize;
  return 0;
}