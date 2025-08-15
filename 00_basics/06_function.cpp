// Functions in C++
#include<bits/stdc++.h>
using namespace std;

// Function to add two numbers
int add(int a, int b) {
  return a + b;
}

// Function to find the maximum of two numbers
int max(int a, int b) {
  return (a > b) ? a : b;
}

// Function to greet
void greet(string name){
  cout << "Hello, " << name << "!" << endl;
}

// Pass by value
void passByValue(int num) {
  num += 100;  // This will not affect the original variable as a copy is sent to the function
  cout << "Inside passByValue: " << num << endl;
}

// Pass by reference - num points to the original variable
void passByReference(int &num) {
  num = 100;  // This will affect the original variable
  cout << "Inside passByReference: " << num << endl;
}

// Pass by address - pointer is passed
void passByAddress(int *num) {
  *num = 100;  // This will affect the original variable
  cout << "Inside passByAddress: " << *num << endl;
}

int main() {
  cout << "Addition: " << add(5, 10) << endl;
  cout << "Maximum: " << max(5, 10) << endl;
  greet("Ayush");
  int n = 50;
  passByValue(n); // This will not get changed as copy is sent to function
  cout << "In main: " << n << endl;
  int num = 50;
  passByReference(num); // This will change the original variable
  cout << "In main: " << num << endl;
  passByAddress(&num); // This will change the original variable
  cout << "In main: " << num << endl;
  return 0;
}