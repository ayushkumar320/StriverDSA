#include<iostream>
using namespace std;

int main() {
  int arr[] = {3, 2, 1, 5, 2};
  // Here largest element is 5

  // Brute force solution:
  // 1. We will sort the array in increasing order
  // 2. The largest element will be at the last index
  // TC - O(n logn)
  // Space - O(1)

  // Optimal solution:
  /*
  1. We will assign first element as largest element.
  2. We will transverse through the whole array and compare all the elements
  3. If we find any element greater than largest element, we will update largest element.
  */

  // The time complexity is O(n) which is better than O(n log n)
  int largest = arr[0];
  int n = sizeof(arr)/sizeof(arr[0]);
  for (int i = 1; i < n; i++) {
    if (arr[i] > largest) {
      largest = arr[i];
    }
  }
  cout << largest;
  return 0;
}