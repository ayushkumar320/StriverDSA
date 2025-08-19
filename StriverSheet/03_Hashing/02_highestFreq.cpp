/*
Given an array nums of n integers, find the most frequent element in it i.e., the element that occurs the maximum number of times. If there are multiple elements that appear a maximum number of times, find the smallest of them.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int mostFrequentElement(vector<int>& nums) {
      map<int, int> mpp;
      for(int i = 0; i < nums.size(); i++) {
        mpp[nums[i]]++;
      }
      int maxFreq = 0;
      int mostFreqElement = 0;
      for (auto it : mpp) {
        if(it.second > maxFreq) {
          maxFreq = it.second;
          mostFreqElement = it.first;
        } else if(it.second == maxFreq) {
          mostFreqElement = min(mostFreqElement, it.first);
        }
      }
      return mostFreqElement;
    }
};
