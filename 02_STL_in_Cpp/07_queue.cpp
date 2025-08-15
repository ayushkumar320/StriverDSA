#include<bits/stdc++.h>
using namespace std;

void explainQueue();

int main(){
  explainQueue();
  return 0;
}

// Queue works in principle of FIFO (First In First Out)
void explainQueue(){
  queue<int> q;
  q.push(1); // {1}
  q.push(2); // {1, 2}
  q.push(3); // {1, 2, 3}
  q.emplace(4); // {1, 2, 3, 4}

  q.back()+=5; // {1, 2, 3, 9}

  // Displaying the front element
  cout << "Front element: " << q.front() << endl;

  // Popping the front element
  q.pop();
  cout << "Front element after pop: " << q.front() << endl;

  // Checking if the queue is empty
  if(q.empty()){
    cout << "Queue is empty" << endl;
  } else {
    cout << "Queue is not empty" << endl;
  }
}