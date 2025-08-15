/*
1      1
12    21
123  321
12344321

*/

#include<bits/stdc++.h>
using namespace std;

void printPattern(int n){
  
  // first space = 2*(n-1) then rest gets reduces by 2
  int spaces = 2*(n-1);
  
  for(int i = 1; i <= n; i++){
    // numbers
    for(int j = 1; j <= i; j++){
      cout << j;
    }
    
    // space
    
    for(int j = 1; j <= spaces; j++){
      cout << " ";
    }

    // number
    for(int j = i; j>=1; j--){
      cout << j;
    }
    cout << endl;
    spaces-=2;
  }
}

int main(){
  printPattern(4);
  return 0;
}