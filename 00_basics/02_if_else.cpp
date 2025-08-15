#include<bits/stdc++.h>
using namespace std;

int main(){
  
  // If else statement are used to make decisions based on condition

  int age;
  cin >> age;

  if (age >= 18) {
    cout << "You are an adult!" << endl;
  } else {
    cout << "You are not an adult!" << endl;
  }

  // If-elseif ladder
  if (age < 13) {
    cout << "You are a child!" << endl;
  } else if (age < 18) {
    cout << "You are a teenager!" << endl;
  } else {
    cout << "You are an adult!" << endl;
  }

  return 0;
}