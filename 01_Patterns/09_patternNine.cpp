#include<bits/stdc++.h>
using namespace std;

void printPatternUp(int n){
  for(int i = 0; i < n; i++){
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
void printPatternDown(int n){
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
  printPatternUp(5);
  printPatternDown(5);
  return 0;
}