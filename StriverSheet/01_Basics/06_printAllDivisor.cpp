#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> divisors(int n) {
      vector<int> result;
      for(int i = 1; i <= n; i++){
        if(n % i == 0){
          result.emplace_back(i);
        }
      }
      return result;
    }
};