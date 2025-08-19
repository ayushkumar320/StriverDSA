#include<bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cout << "Enter the string: ";
  cin >> s;

  // Precompute
  map<char, int> mpp;
  for(int i = 0; i < s.size(); i++){
    mpp[s[i]]++;
  }

  // Printing
  for(auto it : mpp){
    cout << it.first << " -> " << it.second << endl;
  }
  return 0;
}