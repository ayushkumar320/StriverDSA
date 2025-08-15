/*

* * * * *
* * * *
* * *
* *
*

*/

#include<bits/stdc++.h>
using namespace std;

void printPattern(int n){
  for(int i = 0; i < n; i++){
    // Columns - nth row
    for(int j = n - i ; j > 0; j--){
      cout << '*' << " ";
    }
    cout << endl;
  }
}

int main(){
  printPattern(5);
  return 0;
}