#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int secondLargestElement(vector<int>& nums) {
    int largest = nums[0];
    int second_largest = -1;
    for(int i = 1; i < nums.size(); i++) {
      if (nums[i] > largest) {
        second_largest = largest;
        largest = nums[i];
      } else if (nums[i] > second_largest && nums[i] != largest) {
        second_largest = nums[i];
      }
    }
    return second_largest;
  }
};