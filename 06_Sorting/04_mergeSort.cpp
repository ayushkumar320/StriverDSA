// Code for merge sort
#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high) {
  vector <int> temp;
  int left = low;
  int right = mid + 1;
  while (left <= right && right <= high) {
    if(arr[left] < arr[right]){
      temp.push_back(arr[left]);
      left++;
    } else {
      temp.push_back(arr[right]);
      right++;
    }
  }
  while (left <= mid) {
    temp.push_back(arr[left]);
    left++;
  }
  while (right <= high) {
    temp.push_back(arr[right]);
    right++;
  }
  // Copying the merged items back to original array
  for (auto it : temp) {
    arr[low] = it;
    low++;
  }
}

void mergeSort(vector <int> &arr, int low, int high) {
  if (low >= high) return;
  int mid = (low + high) / 2;
  mergeSort(arr, low, mid);
  mergeSort(arr, mid+1, high);
  merge(arr, low, mid, high);
}

void sortArray(vector<int> &arr) {
  int low = 0;
  int high = arr.size()-1;
  mergeSort(arr, low, high);
}

int main() {
  vector<int> arr = {5, 2, 9, 1, 5, 6};
  sortArray(arr);
  for (auto it : arr) {
    cout << it << " ";
  }
  return 0;
}