#include<bits/stdc++.h>
using namespace std;

void explainStack();

int main(){
  explainStack();
  return 0;
}

// Stack works in principle of LIFO (Last In First Out)
void explainStack(){
  // Declaring a stack
  stack<int> st;

  // Pushing elements onto the stack, it pushes at the first position
  st.push(1); // {1}
  st.push(2); // {2, 1}
  st.push(3); // {3, 2, 1}

  // Displaying the top element
  cout << "Top element: " << st.top() << endl;

  // Popping the top element
  st.pop();
  cout << "Top element after pop: " << st.top() << endl;

  // Checking if the stack is empty
  if(st.empty()){
    cout << "Stack is empty" << endl;
  } else {
    cout << "Stack is not empty" << endl;
  }
}