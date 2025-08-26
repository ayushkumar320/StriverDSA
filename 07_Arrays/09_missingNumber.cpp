#include<bits/stdc++.h>
using namespace std;

// We are including 0 to be given as input, if array starts is of only natural numbers, then n will be nums.size() + 1 as one element is always missing.
int bruteForceWay(vector<int> nums) {
  int N = nums.size();  // Range is 0 to N
  for(int i = 0; i <= N; i++) {
    bool found = false;
    for(int j = 0; j < nums.size(); j++) {
      if (nums[j] == i) {  // Found i in array
        found = true;
        break;
      }
    }
    if (!found) {  // i is missing
      return i;
    }
  }
  return -1; // If everything is there return -1.
}

int sumWay(vector<int> nums) {
  int n = nums.size(); 
  int total = (n*(n+1))/2;
  int array_sum = 0;
  for (auto it : nums) {
    array_sum += it;
  }
  return total - array_sum;
}

int xorMethod(vector<int> nums) {
  int xor2 = 0;
  int xor1 = 0;
  int n = nums.size();
  for(int i = 0; i < n; i++) {
    xor2 ^= nums[i];
    xor1 ^= (i + 1);
  }
  return (xor1 ^ xor2); // Missing number
}

int hashingWay(vector<int> nums) {
  int n = nums.size();
  int hash[n+1] = {0};
  for(int i = 0; i < n; i++) {
    hash[nums[i]]++;
  }
  for(int i = 0; i <= n; i++) {
    if (hash[i] == 0) {
      return i;
    }
  }
}

int main() {
  vector<int> nums = {3, 0, 1};
  cout << "Missing number (Brute Force): " << bruteForceWay(nums) << endl;
  cout << "Missing number (Sum Method): " << sumWay(nums) << endl;
  cout << "Missing number (XOR Method): " << xorMethod(nums) << endl;
  cout << "Missing number (Hashing): " << hashingWay(nums) << endl;
  return 0;
}