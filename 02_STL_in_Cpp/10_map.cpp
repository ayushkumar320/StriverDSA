#include<bits/stdc++.h>
using namespace std;

void explainMap();

int main(){
  explainMap();
  return 0;
}
// Map - Associative container that stores elements in key-value pairs
void explainMap(){
  map<int, string> m;
  m[1] = "One";
  m[2] = "Two";
  m[3] = "Three";
  m[4] = "Four";
  m[5] = "Five";

  cout << "Elements in the map: " << endl;
  for(auto it = m.begin(); it != m.end(); ++it){
    cout << it->first << ": " << it->second << endl;
  }

  // Accessing an element
  cout << "Element with key 3: " << m[3] << endl;

  // Erasing an element
  m.erase(2);
  cout << "Elements in the map after erasing key 2: " << endl;
  for(auto it = m.begin(); it != m.end(); ++it){
    cout << it->first << ": " << it->second << endl;
  }

  // Checking if a key exists
  if(m.find(4) != m.end()){
    cout << "Key 4 exists in the map" << endl;
  } else {
    cout << "Key 4 does not exist in the map" << endl;
  }

  // Checking if the map is empty
  if(m.empty()){
    cout << "Map is empty" << endl;
  } else {
    cout << "Map is not empty" << endl;
  }
}