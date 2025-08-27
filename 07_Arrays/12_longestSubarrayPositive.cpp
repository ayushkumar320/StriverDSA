#include<bits/stdc++.h>
using namespace std;

// Brute force way
int bruteWay(vector<int> nums, int k) {
  int length = 0;
  for(int i = 0; i < nums.size(); i++) {
    int sum = 0;
    for(int j = i; j < nums.size(); j++) {
      sum += nums[j];
      if (sum == k) {
        length = max(length, j - i + 1);
      }
    }
  }
  return length;
}

// Better approach (Using hash maps)
int hashWay(vector<int> nums, int k) {
  map<long long, int> preSumMap;
  long long sum = 0;
  int maxLen = 0;
  for(int i = 0; i < nums.size(); i++) {
    sum += nums[i];
    if(sum == k) {
      maxLen = max(maxLen, i + 1);
    }
    long long rem = sum - k;
    if (preSumMap.find(rem) != preSumMap.end()) {
      int len = i - preSumMap[rem];
      maxLen = max(maxLen, len);
    }
    if(preSumMap.find(sum) == preSumMap.end() ) {
      preSumMap[sum] = i;
    }
  }
  return maxLen;
}

// Optimal 
int optimalWay(vector<int> nums, long long k) {
  int left = 0, right = 0;
  long long sum = nums[0];
  int maxLen = 0;
  int n = nums.size();
  while(left < n) {
    while (left <= right && sum > k) {
      sum -= nums[left];
      left++;
    }
    if(sum == k) {
      maxLen = max(maxLen, right - left + 1);
    }
    right++;
    if(right < n) sum += nums[right];
  }
  return maxLen;
}

int main() {
  vector<int> arr = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
  int k = 3;
  cout << hashWay(arr, k);
}