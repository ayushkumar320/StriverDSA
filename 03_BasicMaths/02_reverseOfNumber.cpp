#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cout << "Enter the number: ";
  cin >> n;
  int reversedNum = 0;
  while (n > 0){
    int lastDigit = n % 10;
    reversedNum = reversedNum * 10 + lastDigit;
    n = n / 10;
  }
  cout << "Reversed Number: " << reversedNum << endl;
  return 0;
}