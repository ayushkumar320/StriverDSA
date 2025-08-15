/*

    *      --> 4 space rows = 5(n), if i = 0, space = n-i+1
   ***     --> 3 space
  *****    --> 2 space
 *******   --> 1 space
*********  --> 0 space


*/

#include<bits/stdc++.h>
using namespace std;

void printPattern(int n){
  for(int i = 0; i < n; i++){
    // We are printing space, stars, space
    // [space, stars, space]
    // [4, 1, 4]
    // [3, 3, 3]
    // [2, 5, 2]
    // [1, 7, 1]
    // [0, 9, 0]
    // space - (n-i-1), stars = (2*i+1)
    
    // space
    for(int j = 0; j < n-i-1; j++){
      cout << " ";
    }
    // star
    for(int j = 0; j < 2*i+1; j++){
      cout << '*'; 
    }
    // space
    for(int j = 0; j < n-i-1; j++){
      cout << " ";
    }
    cout << endl;
  }
}

int main(){
  printPattern(5);
  return 0;
}
