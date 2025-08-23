#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool check(vector<int> &nums) {
    int n = nums.size();
    int breaks = 0; // Counts the number of times nums[i] > nums[i+1]

    for (int i = 0; i < n; i++) {

      if (nums[i] > nums[(i + 1) % n]) {
        breaks++;
      }
    }
    return breaks <= 1;
  }
};