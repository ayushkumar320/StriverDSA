#include<bits/stdc++.h>
using namespace std;

vector<int> bruteForceWay(vector<int> &arr1, vector<int> &arr2) {
  set<int> s;
  // Now will iterate through the arrays and store unique elements in set
  for(int i = 0; i < arr1.size(); i++) {
    s.insert(arr1[i]);
  }
  for(int i = 0; i < arr2.size(); i++) {
    s.insert(arr2[i]);
  }
  // Now will convert set to vector
  vector<int> unionArr(s.begin(), s.end()); // This line copies elements from set to vector
  return unionArr;
}

// Optimal solution using two pointer system
vector<int> optimalWay (vector<int> a, vector<int> b) {
  int n1 = a.size();
  int n2 = b.size();
  int i = 0, j = 0; // Setting up pointers
  vector<int> unionArr;
  while(i < n1 && j < n2) {
    if(a[i] <= b[j]) {
      if(unionArr.size() == 0 || unionArr.back() != a[i]) {
        unionArr.push_back(a[i]);
      } 
      i++;
    } else {
      if (unionArr.size() == 0 || unionArr.back() != b[j]) {
        unionArr.push_back(b[j]);
      } 
      j++;     
    }
  }
  // Now if any of the array got exhaused
  while (i < n1) {
    if(unionArr.size() == 0 || unionArr.back() != a[i]) {
      unionArr.push_back(a[i]);
    } 
    i++;
  }
  while (j < n2) {
    if (unionArr.size() == 0 || unionArr.back() != b[j]) {
      unionArr.push_back(b[j]);
    } 
    j++;
  }
  return unionArr;
}

int main() {
  vector<int> arr1 = {1, 1, 2, 3, 4 ,5};
  vector<int> arr2 = {2, 3, 4, 4, 5, 6};
  vector<int> unionArr = optimalWay(arr1, arr2);
  for (auto it : unionArr) {
    cout << it << " ";
  }
  return 0;
}