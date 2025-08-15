#include<bits/stdc++.h>
using namespace std;

void explainSet();
void explainMultiSet();

int main(){
  explainSet();
  explainMultiSet();
  return 0;
}

// Set works on the principle of unique elements where each element can only appear once
void explainSet(){
  set<int> s;
  s.insert(1);
  s.insert(3);
  s.insert(2);
  s.insert(5);
  s.insert(4);

  cout << "Elements in the set: ";
  for(auto it = s.begin(); it != s.end(); ++it){
    cout << *it << " ";
  }
  cout << endl;

  s.erase(3);
  cout << "Elements in the set after erasing 3: ";
  for(auto it = s.begin(); it != s.end(); ++it){
    cout << *it << " ";
  }
  cout << endl;

  if(s.empty()){
    cout << "Set is empty" << endl;
  } else {
    cout << "Set is not empty" << endl;
  }

  auto it = s.find(2);   // returns and iterator which points to 2 (address of 2 in set)
  if(it != s.end()){
    cout << "Element 2 found in the set" << endl;
  } else {
    cout << "Element 2 not found in the set" << endl;
  }
}

// Multiset - Allows duplicate elements
void explainMultiSet(){
  multiset<int> ms;
  ms.insert(1);
  ms.insert(3);
  ms.insert(2);
  ms.insert(5);
  ms.insert(4);
  ms.insert(2);  // Duplicate element

  cout << "Elements in the multiset: ";
  for(auto it = ms.begin(); it != ms.end(); ++it){
    cout << *it << " ";
  }
  cout << endl;

  ms.erase(2);  // Removes all occurrence of 2
  cout << "Elements in the multiset after erasing 2: ";
  for(auto it = ms.begin(); it != ms.end(); ++it){
    cout << *it << " ";
  }
  cout << endl;

  if(ms.empty()){
    cout << "Multiset is empty" << endl;
  } else {
    cout << "Multiset is not empty" << endl;
  }

  auto it = ms.find(2);
  if(it != ms.end()){
    cout << "Element 2 found in the multiset" << endl;
  } else {
    cout << "Element 2 not found in the multiset" << endl;
  }
} 