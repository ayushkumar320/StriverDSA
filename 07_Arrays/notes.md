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
  