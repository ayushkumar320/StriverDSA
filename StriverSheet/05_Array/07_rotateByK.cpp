#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  void rotateArray(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
  }
};

int main() {
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
  Solution sol;
  sol.rotateArray(arr, 3);
  for (auto it : arr) {
    cout << it << " ";
  }
  return 0;
}