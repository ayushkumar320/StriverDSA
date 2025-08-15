#include<bits/stdc++.h>
using namespace std;
void explainPair();

int main(){
  explainPair();
  return 0;
}

// Pairs
void explainPair(){
  
  pair<int, int> p = {1, 3};    // Intializing a pair of integers

  cout<<p.first<<" "<<p.second<<endl;  // Elements can be accessed using dot first and dot second    

  pair<int, pair<int, int>> q = {1, {3, 4}};   // Nested pair to store 3 values
  
  cout<<q.first<<" "<<q.second.first<<" "<<q.second.second<<endl;

  // Nested pair to store 4 values

  pair<pair<int, int>, pair<int, int>> r = {{1, 2}, {3, 4}};
  cout<<r.second.second<<endl;

  pair<int, int> arr[] = { {1, 2}, {2, 5}, {5,1}};   // Storing an array of pairs

  cout<<arr[1].second;
}