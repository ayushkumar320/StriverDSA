#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> bubbleSort(vector<int>& nums) {
      int n = nums.size();
      for(int i = n-1; i >= 0; i--){
        int didSwap = 0;
        for (int j = 0; j <= i-1; j++){
          if (nums[j] > nums[j+1]){
            swap(nums[j], nums[j+1]);
            didSwap = 1;
          }
        }
        if(didSwap == 0) break;
      }
      return nums;
    }
};
