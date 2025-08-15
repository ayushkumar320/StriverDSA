/*

*********
 *******
  *****
   ***
    *

*/

#include<bits/stdc++.h>
using namespace std;

void printPattern(int n){
  for(int i = 0; i < n; i++){
    // Space
    for(int j = 0; j < i; j++){
      cout << " ";
    }
    // Star
    for(int j = 2*(n-i) - 1; j > 0; j--){
      cout << '*';
    }
    // Space
    for(int j = 0; j < i; j++){
      cout << " ";
    }
    cout << endl;
  }
}

int main(){
  printPattern(5);
  return 0;
}