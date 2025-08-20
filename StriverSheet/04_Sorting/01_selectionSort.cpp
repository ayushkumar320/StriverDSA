#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> selectionSort(vector<int>& nums) {
      int n = nums.size();
      int min;
      for(int i = 0; i < n-1; i++){
        min = i;
        for(int j = i; j < n; j++){
          if (nums[j] < nums[min]){
            min = j;
          };
        }
        swap(nums[min], nums[i]);
      }
      return nums;
    }
};
