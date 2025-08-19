#include<bits/stdc++.h>
using namespace std;

// Map - stores in key value pair

int main() {
  
  // Declaring an array first
  int n;
  cout << "Enter the number of elements of array: ";
  cin >> n;

  int arr[n];

  // Initalizing an array:
  cout << "Enter the elements of an array\n";
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }

  // Using maps to precompute the frequency, it is dynamic in nature
  
  map<int, int> mpp;
  for(int i = 0; i < n; i++){
    mpp[arr[i]]++;
  }

  // Prompting user for number of queries to pass
  int q;
  cout << "Enter the number of queries you want to run: ";
  cin >> q;

  cout << "Enter the numbers to display the frequence\n";
  while(q--) {
    int number;
    cin >> number;
    cout << "Element " << number << " has frequency " << mpp[number] << endl;
  }
  
  // Map stores everything in order
  for(auto it : mpp) {
    cout << "Element " << it.first << " has frequency " << it.second << endl;
  }
  return 0;
}