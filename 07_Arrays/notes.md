# Array

- An array is a data structure which can store similar elements.
- If the array is of integers, it can store multiple integer values in a single variable not any string.
- Array can be of any data type: string, integer, pair<int, int>
- To define an array:
  ```cpp
  int arr[5];
  ```
  - It will create an array with 5 elements all of them will be stored with garbage value if it is declared inside `int main()`.
  - If we define the array outside the main function, i.e as global function, it will be initialized with 0.
  - Maximum size of integer array is `10^6` when we declare it inside `int main()` and size of array is `10^7` when we declare it outside the main function or globally.
  - The first index of array is `0` then followed by 1, 2 and so on.
  - Last index is `size-1`.
  - We can access the whole array using a loop.
  ```cpp
  for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
    cout << arr[i] << " ";
  }
  ```
- We can also initialize an array at the time of declaration.
  ```cpp
  int arr[5] = {1, 2, 3, 4, 5};
  ```
- If we don't initialize the array, it will contain garbage values.

## Where is array stored in memory:

- Array elements are stored in contiguous memory locations.
- The base address of the array is the address of the first element.
- The address of the i-th element can be calculated as:
  ```
  address(arr[i]) = base_address + i * sizeof(data_type)
  ```
- This allows for efficient access to array elements using pointer arithmetic.

## Second largest problem

Given an array [1, 2, 4, 7, 7, 5] we need to find the 2nd largest element.

1. **Brute force approach:**

- We will first sort the array in ascending order
- Now technically the 2nd largest element will be at index `n-2` but there can be possibility that `n-2`th element can be equal to that of `n-1` or the largest element.
- So we will provide a check as follows:
  ```cpp
    int largest = arr[n-1];
    for(int i = n-2; i >= 0; i--) {
      if (arr[i] != largest) {
        cout << arr[i];
        break;
      }
    }
  ```
  - For a sorted array, this will give us the second largest element.
- The time complexity is O(n log n + n) due to sorting.

2. **Better solution:**

- In first pass or first traversal of array, we will find the largest element
  ```cpp
    int largest = arr[0];
    for (int i = 1; i < n; i++) {
      if (arr[i] > largest) {
        largest = arr[i];
      }
    }
  ```
- Now in the second pass:

  1. We will assign `second_largest` to `-1`, considering array does not contain any negative elements if so, we assign `second_largest` to `INT_MIN`.
  2. Now we will traverse the array again and find the second largest element by skipping the largest element.

  ```cpp
    int second_largest = -1;
    for (int i = 0; i < n; i++) {
      if (arr[i] > second_largest && arr[i] != largest) {
        second_largest = arr[i];
      }
    }
  ```

- The time complexity of this approach is O(n) + O(n) = O(2n) which is approximately O(n) which is better approach.

3. **Optimal Approach:**

- We will assign `largest` to `arr[0]` and second_largest to `-1`, considering array does not contain any negative elements if so, we assign `second_largest` to `INT_MIN`.
- If someone becomes the largest the previous largest will become the second largest.
  ```cpp
    int largest = arr[0];
    int second_largest = INT_MIN;
    for (int i = 1; i < n; i++) {
      if (arr[i] > largest) {
        second_largest = largest;
        largest = arr[i];
      } else if (arr[i] > second_largest && arr[i] != largest) {
        second_largest = arr[i];
      }
    }
    return {largest, second_largest};
  ```

## Check if array is sorted

- Simple principle to check
- We will check if `arr[i] >= arr[i-1]`. If it it true for `i = 1 to i < n` we will return true, else false
- Takes a single pass, Time complexity is O(n).

## Remove duplicates from soted array:
- For given an array we need to remove the duplicate element and return the array with unique elements.
1. **Brute Force:**
  - We can use set data structure to store unique elements.
  - Traverse the array and insert elements into the set.
  - Finally, copy the elements from the set back to the array.
  - As set data structure does not allow duplicates, we will have unique elements in the set.
  - After one iteration we will have all unique elements in the set.
  ```cpp
    set<int> st;
    for(int i = 0; i < n; i++) {
      st.insert(arr[i]);     // Takes O(n log n)
    } 
    // Placing it back to the array
    int index = 0;
    for (auto it : st) {
      arr[index] = it;
      index++;
    }
    return index; // New size of the array
  ```
  - The time complexity of this approach is O(n log n + n) due to the set operations.
  - The space complexity is also O(n) due to the set storing unique elements.

2. **Optimal Approach:**

- We will use two pointers to keep track of the unique elements.
- The first place will be always be taken by the first element.
- The next element will be someone which is not equal to the first element.
- We will move the first pointer to next place and will replace the value with second pointed which is not equal to the first element.
- We will follow the same process until we reach the end of the array.
- Time complexity is O(n) due to the single pass through the array.
- Space complexity is O(1) as we are not using any extra space.

  ```cpp
    int i = 0; 
    for(int j = 1; j < n; j++) {
      if (arr[j] != arr[i]) {
        arr[i+1] = arr[j];
        i++;
      }
    }
    return (i+1);
  ```
---

# Part 2

## Array Rotation: 

### Left rotate an array by 1 place:
- Given an array we have to rotate an array by one place.
- Lets say, we have an array ```arr[] = {1, 2, 3, 4 ,5}```
- Left rotation means, the leftmost element will be moved to the rightmost position by one step.
- After rotation:
  - Rotated array will be ```arr[] = {2, 3, 4, 5, 1}```

1. **Brute Force:**
  - We can take a new array.
  - In new array, we can copy elements from the original array starting from index 1 to the end, and then place the first element at the end.
  ```cpp
  int n = sizeof(arr) / sizeof(arr[0]);
  int new_arr[n];
  for (int i = 1; i < n; i++) {
    new_arr[i - 1] = arr[i];
  }
  new_arr[n - 1] = arr[0];
  ```
  - Time Complexity is O(n).
  - Space Complexity is O(n).
2. **Better Approach:**
- We can store first value in a temp variable.
- After that we will shift all other array elements to the left by one position.
- Finally, we will place the temp variable at the end of the array.
  ```cpp
  int temp = arr[0];
  for (int i = 1; i < n; i++) {
    arr[i - 1] = arr[i];
  }
  arr[n - 1] = temp;
  ```
- Time Complexity is O(n).
- Space Complexity is O(1).

### Left rotate an array by D places
- Let array be ```arr[] = {1, 2, 3, 4, 5 ,6 ,7}```
- Suppose we want to rotate by d = 2
- After rotation:
  - Rotated array will be ```arr[] = {3, 4, 5, 6, 7, 1, 2}```
- For rotation of d = 7
- After rotation:
  - Rotated array will be ```arr[] = {1, 2, 3, 4, 5, 6, 7}```
  - It will be same as original array.
  - Anything beyond the length of the array will wrap around.
  - For 8 rotation, we only need to rotate by 1 (8-7).
  - This means we can reduce the number of rotations by taking modulo with the array length.
  - For d = 15 => 15 % 7 = 1, we just have to rotate by 1.
1. **Brute Force:**
  - Let arr[] = [1, 2, 3, 4, 5, 6 ,7] and d = 3
    ```cpp
      d = d % n;
      int temp[] = {1, 2, 3};
      // Next job is shifting
      for(int i = d; i < n; i++) {
        arr[i-d] = arr[i];
      }
      // Putting the temp array back
      int j = 0;
      for(int i = n - d; i < n; i++) {
        arr[i] = temp[j];
        j++;
        // Or to remove involvement of j
        // arr[i] = temp[i - (n-d)];
      }
    ```
  - Time complexity is O(n).
  - Space complexity is O(n).

2. **Optimal Solution:**
  - We can reverse the first d element of the array.
  - We can reverse the remaining elements of the array.
  - And finally, we can reverse the entire array to get the desired output.
  ```cpp
  // Where a is the array and n is the length
    reverse(a, a+d);
    reverse(a+d, a+n);
    reverse(a, a+n);
  ```

  - To rotate the array right:
  - We can use the same approach as left rotation, but with a slight modification.
  - We will first reverse the entire array.
  - Then we will reverse the first k elements.
  - Finally, we will reverse the remaining elements.
  ```cpp
  // Where a is the array and n is the length
    reverse(a, a+n);
    reverse(a, a+k);
    reverse(a+k, a+n);
  ```
  - Overall time complexity is O(n) and space complexity is O(1).

## Moving Zeros to the end:
- Let an array `arr[] = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1}` 
- We need to move all the zeros to the end of the array while maintaining the order of non-zero elements.
1. **Brute Force:**
  - We can take a new array and copy all non-zero elements to it.
  - Then we can fill the remaining positions with zeros.
  ```cpp
    int n = sizeof(arr) / sizeof(arr[0]);
    int new_arr[n];
    int index = 0;
    for (int i = 0; i < n; i++) {
      if (arr[i] != 0) {
        new_arr[index] = arr[i];
        index++;
      }
    }
    // Putting all the non zero elements in actual array
    for (int i = 0; i < n; i++) {
      arr[i] = new_arr[i];
    }
    // Putting all the zeros at the end
    for (int i = index; i < n; i++) {
      arr[i] = 0;
    }
  ```
  - Time complexity is O(n).
  - Space complexity is O(n).
2. **Optimal Solution:**
  - We can use two pointer system where while iterating, we can swap the place of zero with the next non zero element.
  - Here i will iterate through the array and j will keep track of the position to place the next non-zero element.
  ```cpp
    int n = sizeof(arr) / sizeof(arr[0]);
    int j = -1;
    // Finding the first 0th element
    for(int i = 0; i < n; i++) {
      if(arr[i] == 0) {
        j = i;
        break;
      }
    }
    if(j==-1) return;
    for(int i = j + 1; i < n; i++) {
      if(arr[i] != 0) {
        swap(arr[i], arr[j]);
        j++;
      }
    }
  ```
  - Time Complexity is O(n).
  - Space Complexity is O(1). As we are not using any extra space to store temporary array.

## Union of two sorted arrays:
- Union means combining the elements of two arrays into a single array, without duplicates.
- Let first array be `arr1[] = {1, 1, 2, 3, 4, 5}`
- Let second array be `arr2[] = {2, 3, 4, 5, 6}`
- The union of these two arrays will be `arr[] = {1, 2, 3, 4, 5, 6}`

1. **Brute Force Approach:**
  - We can take a new array and copy all elements from both arrays to it.
  - Then we can remove duplicates from the new array.
  - When we hear unique, something like map or set comes in picture as they store only unique elements.
  ```cpp
    // Lets take a set data structure
    set<int> s;
    // Now we will iterate through both arrays and insert elements into the set
    for (int i = 0; i < arr1.size(); i++) {
      s.insert(arr1[i]);    // -- O(n1 log n1) where n1 is size of array
    }
    for (int i = 0; i < arr2.size(); i++) {
      s.insert(arr2[i]);    // -- O(n2 log n2)
    }
    // Now we can copy the elements from the set to the result array
    vector<int> unionArr(s.begin(), s.end());
  ```
  - The Time Complexity of this set approach if every element is unique O(n1 log n1 + n2 log n2)
  - The Space Complexity is O(n1 + n2) due to the set storing unique elements.

2. **Optimal Approach:**
  - Only if both the arrays are sorted, we can use a two pointer approach
  - We will assign an i pointer to first array and j pointer to 2nd array and will iterate through both arrays
  - We will add the elements by comparing the elements at the i and j pointers
  - If the elements are equal, we will add it to the result array and move both pointers
  - If the element in the first array is smaller, we will move the i pointer
  - If the element in the second array is smaller, we will move the j pointer
  - This way we can find the union in O(n1 + n2) time
  ```cpp
    vector<int> sortedArray(vector<int> a, vector<int> b) {
      int n1 = a.size();
      int n2 = b.size();
      int i = 0;
      int j = 0;
      vector<int> unionArr;
      while(i < n1 && j < n2) {
        if (a[i] <= b[j]) {
          if(uniorArr.size() == 0 || unionArr.back() != a[i]) {
            unionArr.push_back(a[i]);
          }
          i++;
        }
        else {
          if(uniorArr.size() == 0 || unionArr.back() != b[j]) {
            unionArr.push_back(b[j]);
          }
          j++;
        }
      }
      // If the arrays got exhausted
      while(j < n2) {
        if(uniorArr.size() == 0 || unionArr.back() != b[j]) {
          unionArr.push_back(b[j]);
        }
        j++;
      }
      while(i < n1) {
        if(uniorArr.size() == 0 || unionArr.back() != a[i]) {
          unionArr.push_back(a[i]);
        }
        i++;
      }
      return unionArr;
    }
  ```
  - Time complexity is O(n1 + n2).
  - Space complexity is O(n1 + n2) due to the result array storing unique elements.

## Intersection of two sorted array:
- Intersection means finding common elements between two arrays.
1. **Brute Force:**
  - We can use two nested loops to compare each element of the first array with each element of the second array.
  - If we find a match, we add it to the result array.
  ```cpp
    vector<int> intersection(vector<int> a, vector<int> b) {
      vector<int> intersectArr;
      for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
          if (a[i] == b[j]) {
            // To skip duplicates
            if (intersectArr.empty() || intersectArr.back() != a[i]) {
              intersectArr.push_back(a[i]);
            }
          }
        }
      }
      return intersectArr;
    }
  ```
  - Time complexity is O(n1 * n2).
  - Space complexity is O(n1 + n2) due to the result array storing common elements.
2. **Optimal Approach:**
  - If both arrays are sorted, we can use a two-pointer approach.
  - We will assign an i pointer to the first array and a j pointer to the second array and will iterate through both arrays.
  - If we find a match, we will add it to the result array and move both pointers.
  - If the element in the first array is smaller, we will move the i pointer.
  - If the element in the second array is smaller, we will move the j pointer.
  - This way we can find the intersection in O(n1 + n2) time.
  ```cpp
    vector<int> intersection(vector<int> a, vector<int> b) {
      vector<int> intersectArr;
      int i = 0;
      int j = 0;
      while (i < a.size() && j < b.size()) {
        if (a[i] == b[j]) {
          // To skip duplicates
          if (intersectArr.empty() || intersectArr.back() != a[i]) {
            intersectArr.push_back(a[i]);
          }
          i++;
          j++;
        }
        else if (a[i] < b[j]) {
          i++;
        }
        else {
          j++;
        }
      }
      return intersectArr;
    }
  ```
  - Time complexity is O(n1 + n2).
  - Space complexity is O(n1 + n2) due to the result array storing common elements.
