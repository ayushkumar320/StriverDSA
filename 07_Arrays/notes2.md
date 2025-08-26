# Finding missing numbers in an array:
- For given an array `arr[] = {1, 2, 4, 5}`. Here n = 5 (n is the maximum element in the array).
1. **Brute Force**:
  - In outer loop we set the i = 1 and iterate till i <= n.
  - In inner loop we check if i is present in the array or not by linear search.
  ```cpp
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
    return -1; // If everything is there return -1
  ```
  - The time complexity of this approach is O(n^2) in the worst case, as we are using a nested loop to check for the presence of each number from 1 to n in the array.
  - Space complexity is O(1).

2. **Better Approach:**
- We can use the concept of hashing.
- We declare a hash array of size n+1 and initialize all elements to 0.
```cpp
  int hash[n+1] = {0};
  for(int i = 0; i < n; i++) {
    hash[arr[i]] = 1;
  }
  for(int i = 1; i <= n; i++) {
    if (hash[i] == 0) {
      return i;
    }
  }
```
  - Time complexity is O(n) and space complexity is O(n).

3. **Optimal solution:**
- There are two methods, one is sum, other is XOR.

### Sum method
- We can find the sum of the first n natural numbers using the formula: sum = n * (n + 1) / 2
- We can find the sum of the elements in the array.
- The missing number will be: missing = sum - array_sum
```cpp
  sum = n * (n + 1) / 2;
  array_sum = 0;
  for (int i = 0; i < n - 1; i++) { // As one element is missing, so i will go less than n - 1
    array_sum += arr[i];
  }
  missing = sum - array_sum;
  return missing;
```
  - The time complexity of this approach is O(n) and space complexity is O(1).

### XOR Method
- The XOR (^) of same number is always 0
  - a ^ a = 0
  - 2 ^ 2 = 0
- This will be the most optimal solution
```cpp
  int xor1 = 0;
  int xor2 = 0;
  for (int i = 0; i < n - 1 ; i++) {   // i -> n - 1 as one element is missing
    xor2 ^= arr[i]; // This will give us the XOR of all elements in the array in xor2, so xor2 = arr[0] ^ arr[1] ^ ... ^ arr[n-2]
    xor1 ^= (i + 1); // This will give us the XOR of all elements from 1 to n in xor1, so xor1 = 1 ^ 2 ^ ... ^ n
  }
  xor1 ^= n; // Include n in the XOR
  missing = xor1 ^ xor2;
  return missing;
```
  - The time complexity of this approach is O(n) and space complexity is O(1).
  - But it is the most optimal solution among all the discussed methods as for a bigger range of numbers, the XOR method will perform better than the sum method due to the avoidance of potential overflow issues while calculating the sum.

# Maximum Consecutive Ones:

- Given a binary array, find the maximum number of consecutive 1s in this array.
- It can be done by simple iteration through the array and counting the number of consecutive 1s.
```cpp
  int maxCount = 0;
  int count = 0;
  for (int i = 0; i < nums.size(); i++) {
    if(nums[i] == 1) {
      count++;
      maxCount = max(maxCount, count);
    } else {
      count = 0;
    }
  }
  return maxCount;
```
  - The time complexity is simply O(n) and space complexity is O(1).