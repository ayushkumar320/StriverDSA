#include<bits/stdc++.h>
using namespace std;

int bruteForceWay(vector<int> nums) {
  for(int i = 0; i < nums.size(); i++) {
    int count = 0;
    for(int j = 0; j < nums.size(); j++) {
      if(nums[i] == nums[j]) {
        count++;
      }
    }
    if (count == 1) {
      return nums[i];
    }
  }
  return -1;
}

// We can use concept of hashing

int betterWay(vector<int> nums) {
  int maxElement = -1;
  for(int i = 0; i < nums.size(); i++) {
    maxElement = max(maxElement, nums[i]);
  }

  int hash[maxElement + 1] = {0};
  for(int i = 0; i < nums.size(); i++) {
    hash[nums[i]]++;
  }
  for(int i = 0; i <= maxElement; i++) {
    if (hash[i] == 1) {
      return i;
    }
  }
  return -1;
}

// The above hashing technique can note be used for larger elements or negative number, to counter that we can use the map data structure
int mapWay(vector<int> nums) {
  map<long long, int> mpp;
  for(int i = 0 ; i < nums.size(); i++) {
    mpp[nums[i]]++;
  }
  for(auto it : mpp) {
    if (it.second == 1) {
      return it.first;
    }
  }
}

// This is the best way, where we can use the concept of XOR as (a^a = 0)
int xorWay(vector<int> nums) {
  int xor1 = 0;
  for(int i = 0; i < nums.size(); i++) {
    xor1 = xor1 ^ nums[i];
  }
  return xor1;
}

int main() {
  vector<int> nums = {1, 1, 2, 2, 5, 3, 4 ,4, 3};
  cout << "Number that occur once is (Brute Force) " << bruteForceWay(nums) << endl;
  cout << "Number that occur once is (Array hashing) " << betterWay(nums) << endl;
  cout << "Number that occur once is (Map) " << mapWay(nums) << endl;
  cout << "Number that occur once is (XOR Way) " << xorWay(nums) << endl;
  return 0;
}