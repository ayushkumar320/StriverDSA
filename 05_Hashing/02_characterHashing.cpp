// Here the hash array is initialized with size of 256.
#include<bits/stdc++.h>
using namespace std;

int main(void) {
  
  string s;
  cout << "Enter the string: ";
  cin >> s;

  // For convenience we will convert the string to lower case
  // for(int i = 0; i < s.size(); i++) {
  //   s[i] = tolower(s[i]); // works on character
  // }
  // Or, we can use transform to achieve the same result

  transform(s.begin(), s.end(), s.begin(), ::tolower);
  
  // Now character hashing
  int hash[256] = {0}; // Initialize hash array

  // Computing frequency of each character
  for(int i = 0; i < s.size(); i++) {
    hash[s[i]]++;
  }

  // Asking for query and displaying
  int q;
  cout << "Enter the number of query: ";
  cin >> q;
  while(q--) {
    char c;
    cout << "Enter the character to query: ";
    cin >> c;
    cout << "Frequency of " << c << " is: " << hash[c] << endl;
  }

  return 0;
} 