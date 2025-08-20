#include<bits/stdc++.h>
using namespace std;

// Time complexity O(n^2)
// Pattern - n + n-1 + n-2 + ... + 1 = n(n+1)/2
void selection_sort(int arr[], int n) {
  int min;
  for(int i = 0; i < n - 1; i++){ 
    min = i;
    for (int j = i; j < n; j++) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }
    swap(arr[i], arr[min]);
  }
}

int main() {
  int n;
  cout << "Enter the number of elements of array: ";
  cin >> n;
  int arr[n];
  cout << "Enter the elements of the array\n";
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  selection_sort(arr, n);
  cout << "The sorted array is:\n";
  for(int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}