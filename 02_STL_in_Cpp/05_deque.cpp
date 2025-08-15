#include<bits/stdc++.h>
using namespace std;

void explainDeque();

int main(){
  explainDeque();
  return 0;
}

void explainDeque(){

  deque<int>dq;
  dq.push_back(2); // {2}
  dq.emplace_back(4); // {2, 4}
  dq.push_front(5);  // {5, 2, 4}
  dq.emplace_front(1); // {1, 5, 2, 4}

  dq.pop_back(); // {1, 5, 2}
  dq.pop_front(); // {5, 2}

  dq.back(); // 2
  dq.front(); // 5

  // Printing a deque

  for(auto it = dq.begin(); it != dq.end(); it++){
    cout << *it << " ";
  }
  cout<<endl;
  // Manually printing without auto keyword
  for(deque<int>::iterator it = dq.begin(); it != dq.end(); it++){
    cout << *it << " ";
  }
  cout<<endl;

  // Rest all functions are same as vector

}