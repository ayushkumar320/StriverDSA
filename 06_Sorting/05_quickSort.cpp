#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high) {
  int pivot = arr[low];
  int i = low;
  int j = high;
  while (i < j) {
    // First element greater than pivot
    while(arr[i] <= pivot && i <= high - 1) {
      i++;
    }
    // First element less than pivot
    while (arr[j] > pivot && j >= low + 1) {
      j--;
    }
    // agar i aur j cross nahi hua h tohi swap krenge
    if (i < j) {
      swap(arr[i], arr[j]); 
      // This will swap the lower than pivot and greater than pivot element to their respective half
    }
  }
  // Now everything is in thier own territory (higher wale right me and lower wale left me)
  swap(arr[low], arr[j]);
  return j;
}

void qs(vector<int> &arr, int low, int high) {
  if (low < high) {
    int pivotIndex = partition(arr, low, high);
    qs(arr, low, pivotIndex - 1);
    qs(arr, pivotIndex + 1, high);
  }
}

vector<int> quickSort(vector<int> &arr) {
  int low = 0;
  int high = arr.size() - 1;
  qs(arr, low, high);
  return arr;
}

int main() {
  vector<int> arr = {4, 6, 2, 5, 7, 9, 1, 3};
  quickSort(arr);
  for(auto it: arr) {
    cout << it << " ";
  }
  return 0;
}