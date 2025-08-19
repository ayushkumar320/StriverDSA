/*
Given an array nums of size n which may contain duplicate elements, return a list of pairs where each pair contains a unique element from the array and its frequency in the array.

You may return the result in any order, but each element must appear exactly once in the output.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> countFrequencies(vector<int>& nums) {
      unordered_map<int, int> mpp;
      for(int i = 0; i < nums.size(); i++) {
        mpp[nums[i]]++;
      }
      vector<vector<int>> result;
      for(auto it : mpp) {
        result.emplace_back(vector<int>{it.first, it.second});
      }
      return result;
    }
};