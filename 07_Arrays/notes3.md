# Longest Subarray with sum k [positive]: 
- Sub array means contiguous elements of the array.
- We have to find the longest subarray with a sum equal to k.
1. **Brute Force Approach:**
- Generate all subarray and will find everyones sum.
- Keep track of the maximum length of subarray found with sum equal to k.
- **Example:** `arr[] = {}`
  - We can keep a pointer i at arr[0] and another pointer j at i, now we will move j till it reaches last and will keep making subarrays.
  - Once the j reaches the end, move the i pointer to the right and repeat the process.
  ```cpp
    int length = 0;
    for(int i = 0; i < nums.size(); i++) {
      for (int j = i; j < nums.size(); j++) {
        int sum = 0;
        for(int k = i; k <= j; k++) {
          sum += nums[k];
        }
        if (sum == k) {
          length = max(length, j - i + 1);
        }
      }
    }
    return length;
  ```
  - **Time Complexity:** O(n^3)
  - **Space Complexity:** O(1)

2. **Better Brute Force:**
- Instead of calculating the sum of each subarray from scratch, we can maintain a running sum while expanding the subarray.
- We just need to add the new element to the sum and check if it equals k.
- If it does, we update the maximum length found so far.
  ```cpp
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
  ```
  - **Time Complexity:** O(n^2)
  - **Space Complexity:** O(1)

3. **Better Solution Approach:**
- We can use the concept of hashing
- We will maintain a hashmap to store the first occurrence of each prefix sum.
- As we iterate through the array, we calculate the prefix sum and check if it has been seen before.
- If it has, we can calculate the length of the subarray with the desired sum.

### Dry run:
- Let array be `arr[] = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3}`
- Let k = 3
- Lets start with a pointer i at arr[0].
  - Now:
  - i = 0, prefix sum = 1,
    - Since prefix sum < k, we will store 1 in hashmap with key 1 and value 0. The value is nothing but the index of the prefix sum.
  - Now at i = 1, prefix sum = 3,
    - Since prefix sum = k, we will update it in hashmap, with key 3 and value 1.
    - Also we can update the maximum length found so far, and length = 2.
  - Now when we move to i = 2, prefix sum is 6
    - Since prefix sum > k, we will check if (6 - k) exists in the hashmap.
    - Now we will store 6 in the hashmap with key 6 and value 2.
  - Now we will move to i = 3, prefix sum is 7
    - Since prefix sum > k, we will check if (7 - k) exists in the hashmap.
    - If it does, we can calculate the length of the subarray with the desired sum.
    - We will put (7, 3) in the hashmap.
  - Now we will move to i = 4, prefix sum is 8
    - Since prefix sum > k, we will check if (8 - k) exists in the hashmap.
    - If it does, we can calculate the length of the subarray with the desired sum.
    - We will put (8, 4) in the hashmap.
  - Now we will move to i = 5, prefix sum is 9
    - Since prefix sum > k, we will check if (9 - k) exists in the hashmap.
    - If it does, we can calculate the length of the subarray with the desired sum.
    - Here we have (9 - 3) = 6 in the hashmap with value 2.
    - Then length = 5 - 2 = 3.
    - We will put (9, 5) in the hashmap.
  
  ```cpp
    long long preSum = 0;
    map<long long, int> preSumMap;
    int maxLen = 0;
    for(int i = 0; i < nums.size(); i++) {
      preSum += nums[i];
      if (preSum == k) {
        maxLen = max(maxLen, i + 1);
      }
      int rem = preSum - k;
      // Checking if the remaining sum exists in the hashmap
      if (preSumMap.find(rem) != preSumMap.end()) {
        int len = i - preSumMap[rem];
        maxLen = max(maxLen, len);
      }
      preSumMap[preSum] = i;
    }
    return maxLen;
  ```
  **Time Complexity:** TC -> O(n * log n) - Ordered Map and O(n^2) - Unordered map
  **Space Complexity:** O(n)

3. **Optimal Solution:**
- We can use two pointer technique
```cpp
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
```
  **Time Complexity:** O(n) as inner while loop never runs for n times
  **Space Complexity:** O(1)