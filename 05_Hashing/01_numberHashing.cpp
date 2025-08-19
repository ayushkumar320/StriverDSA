#include<bits/stdc++.h>
using namespace std;

int main() {
  // For a given array, we will check how many times
  // 1 4 2 3 12 appears
  int n;
  cout << "Enter the size of array: ";
  cin >> n;
  int arr[n];
  cout << "Enter the array elements\n";
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
 
  int hash[13] = {0};  // Maximum size which can be checked
  
  // This for loop iterates over the main array and increments the count in hash array
  for(int i = 0; i < n; i++){
    hash[arr[i]] += 1;
  }

  // Prompting user for how many numbers he wants to check and then printing its occurance.

  cout << "Enter the number of queries: ";
  int q;
  cin >> q;
  cout << "Enter the query numbers:\n";
  while(q--){
    int number;
    cin >> number;
    // fetch
    if(number < 0 || number > 12) {
      cout << "Error: Query number out of allowed range [0,12]." << endl;
    } else {
      cout << "Query number " << number << " appears ";
      cout << hash[number] << " times." << endl;
    }
  }

  return 0;
}