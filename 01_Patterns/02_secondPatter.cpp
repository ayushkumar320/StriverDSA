/*

*
* *
* * *
* * * *
* * * * *

*/

#include<bits/stdc++.h>
using namespace std;

void pattern2(int n){
  // Outer loop for rows
  for(int i = 0; i < n; i++){
    // Inner loop for column, here row number = number of star
    for(int j = 0; j < i+1; j++){
      cout << '*' <<" ";
    }
    cout << endl;
  }
}

int main(){
  pattern2(5);
  return 0;
}