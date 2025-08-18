// Recursion - Recursion means a function calling itself

/*
f() {
  print(1)
  f()
}

The above function when called in main function, calls itself till infinity and results in a stack overflow error.

Stack overflow - A stack overflow occurs when there is no more space in the call stack to handle new function calls. This typically happens in deep or infinite recursion.

To get rid of infinite recursion, we need to define a base condition that stops the recursion from continuing indefinitely.
*/

#include<bits/stdc++.h>
using namespace std;

int counter = 0; // A global variable which will be used to define base condition

void f() {
  counter++;
  if (counter == 5) return; // Base condition
  cout << counter << endl;
  f();
}

int main(){
  f();
  return 0;
}

// Recursion Tree - 
/* 
A recursion tree is a tree representation of the function calls made during the execution of a recursive function. Each node in the tree represents a function call, and the edges represent the calls made to other functions.
*/