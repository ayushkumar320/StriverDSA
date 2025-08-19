#include<bits/stdc++.h>
using namespace std;

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Using two pointer, its time complexity is O(n)
void reverseArray(int arr[], int first, int last) {
  if(first >= last) return;
  swap(arr[first], arr[last]);
  reverseArray(arr, first+1, last-1);
}

// Using single pointer
void reverseArraySingle(int arr[], int size, int i) {
  if (i > size/2) return;
  swap(arr[i], arr[size - i - 1]);
  reverseArraySingle(arr, size, i + 1);
}

int main(){
  int arr[] = {1, 2, 3, 4, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  // reverseArray(arr, 0, n - 1);
  reverseArraySingle(arr, n, 0);
  for(int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}