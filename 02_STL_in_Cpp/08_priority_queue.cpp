#include<bits/stdc++.h>
using namespace std;

void explainPQ();

int main(){
  explainPQ();
  return 0;
}

// Priority Queue works on the principle of priority where the highest element is always at the top
void explainPQ(){
  priority_queue<int> pq;
  pq.push(1);
  pq.push(3);
  pq.push(2);
  pq.push(5);
  pq.push(4);

  cout << "Top element: " << pq.top() << endl;

  pq.pop();
  cout << "Top element after pop: " << pq.top() << endl;

  if(pq.empty()){
    cout << "Priority Queue is empty" << endl;
  } else {
    cout << "Priority Queue is not empty" << endl;
  }

  // Minimum Heap - Stores elements in ascending order
  priority_queue<int, vector<int>, greater<int>> minHeap;
  minHeap.push(1);
  minHeap.push(3);
  minHeap.push(2);
  minHeap.push(5);
  minHeap.push(4);

  cout << "Top element of Min Heap: " << minHeap.top() << endl;

  minHeap.pop();
  cout << "Top element of Min Heap after pop: " << minHeap.top() << endl;

  if(minHeap.empty()){
    cout << "Min Heap is empty" << endl;
  } else {
    cout << "Min Heap is not empty" << endl;
  }
}