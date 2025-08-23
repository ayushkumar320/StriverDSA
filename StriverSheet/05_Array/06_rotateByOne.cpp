#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> rotate(vector<int> &arr) {
    int n = arr.size();
    int temp = arr[0];
    for (int i = 1; i < n; i++){
      arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
    return arr;
  }
  void rotateArrayByOne(vector<int> &nums) {
    rotate(nums);
  }
};