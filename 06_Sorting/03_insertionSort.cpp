#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n) {
  for(int i = 0; i <= n-1; i++) {
    int j = i;
    while (j > 0 && arr[j-1] > arr[j]) {
      swap(arr[j], arr[j-1]);
      j--;
    }
  }
}

int main() {
  int arr[] = {5, 2, 9, 1, 5, 6};
  int n = sizeof(arr) / sizeof(arr[0]);
  insertionSort(arr, n);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}