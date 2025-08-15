#include<bits/stdc++.h>
using namespace std;

void explainList();

int main(){
  explainList();
  return 0;
}

void explainList(){

  // Declaring a list
  list<int> ls;

  ls.push_back(2); // {2}
  ls.emplace_back(4); // {2, 4}

  ls.push_front(5);  // {5, 2, 4}
  ls.emplace_front(1); // {1, 5, 2, 4}

  // Printing a list

  for(auto it = ls.begin(); it != ls.end(); it++){
    cout << *it << " ";
  }
  cout<<endl;
  // Manually printing without auto keyword
  for(list<int>::iterator it = ls.begin(); it != ls.end(); it++){
    cout << *it << " ";
  }
  cout<<endl;

  // Rest all functions are same as vector

}