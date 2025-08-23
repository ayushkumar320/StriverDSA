#include<bits/stdc++.h>
using namespace std;

int main() {
  vector<int> arr;
  // Filling random input
  for(int i=0; i<10; i++) {
    arr.push_back(rand()%20);
  }
  // Finding second largest using optimal approach
  int largest = arr[0];
  int second_largest = INT_MIN;
  for(int i = 1; i < arr.size(); i++) {
    if (arr[i] > largest) {
      second_largest = largest;
      largest = arr[i];
    } else if (arr[i] > second_largest && arr[i] != largest) {
      second_largest = arr[i];
    }
  }
  cout << "Largest: " << largest << ", Second Largest: " << second_largest << endl;
  return 0;
}