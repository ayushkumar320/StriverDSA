# Sorting
- Sorting is the process of arranging the elements of a list or array in a specific order, typically in ascending or descending numerical order, or lexicographical order for strings.
- There are several algorithms for sorting, each with its own advantages and disadvantages. Some of the most common sorting algorithms include:
  - Bubble Sort
  - Selection Sort
  - Insertion Sort
  - Merge Sort
  - Quick Sort
  - Heap Sort
- The choice of sorting algorithm can depend on various factors, including the size of the dataset, the initial order of the elements, and the specific requirements of the application.

# Selection Sort
- Selection Sort is a simple comparison-based sorting algorithm. It works by transversing through the array and looking for either the highest or lowest element in the unsorted part of the array and swapping it with the first unsorted element (usually the first element).
- We repeat the above process for each element in the array until the entire array is sorted.
- The time complexity of Selection Sort is O(n^2) in all cases (best, average, and worst) because it always goes through the entire unsorted part to find the minimum element.
- Selection Sort is not a stable sort, meaning that it may change the relative order of equal elements.
- Example of code:
  ```cpp
  for(i=0; i<=n-2; i++) {
    min = i;
    for(j=i; j<=n-1; j++) {
      if(arr[j] < arr[min]) {
        min = j;
      }
    }
    swap(arr[i], arr[min]);
  }
  ```
  - The time complexity of this implementation of Selection Sort is O(n^2) in all cases (best, average, and worst) because it always goes through the entire unsorted part to find the minimum element.

# Bubble Sort
- It is a type of sorting in which we compare two consecutive terms and swap them if they are in the wrong order.
- We notice after 1st round of sorting, the maximum element is moved to the last position.
- To sort the whole array, we need to repeat the process for all elements until no swaps are needed.
- The time complexity of Bubble Sort is O(n^2) in the worst and average cases, but it can be O(n) in the best case when the array is already sorted.
- Code snippet for loops where `n` is the size of the array:
  ```cpp
  for(i = n-1; i >= 0; i--){
    for (j = 0; j <= i-1; j++) {
      if (arr[j] > arr[j+1]) {
        swap(arr[j], arr[j+1]);
      }
    }
  }
  ```

# Insertion Sort
- It is a comparison-based sorting algorithm that builds a sorted array (or list) one element at a time.
- It works by dividing the array into a sorted and an unsorted region. Initially, the sorted region is empty, and the unsorted region contains all the elements.
- The algorithm repeatedly takes the first element from the unsorted region and inserts it into the correct position in the sorted region.
- The time complexity of Insertion Sort is O(n^2) in the worst and average cases, but it can be O(n) in the best case when the array is already sorted.
- Code snippet for loops where `n` is the size of the array:
  ```cpp
  for(i = 0; i <= n-1; i++){
    j = i;
    while(j > 0 && arr[j-1] > arr[j]){
      swap(arr[j-1], arr[j]);
      j--;
    }
    arr[j] = arr[j-1];
  }
  ```

# Merge Sort
- Merge sort works on principle of divide and merge.
- Lets say we have an araay of 9 elements : [3, 1, 2, 4, 1, 5, 2, 6, 4]
  - We can divide it in 5-4 elements i.e [3, 1, 2, 4, 1] and [5, 2, 6, 4]
  - Not lets take the left array and divide it again in two parts
  - [3, 1, 2] and [4, 1]
  - Now we can further divide [3, 1, 2] into [3, 1] and [2]
  - [3, 1] can be divided into [3] and [1]
  - Now we can merge [3] and [1] in sorted order to get [1, 3]
  - Now we come back, we have [1, 3] and [2], now we will try to merge them in sorted order to get [1, 2, 3]
  - Now we have [1, 2, 3] and [4, 1], we will merge them to get [1, 1, 2, 3, 4]
  - The left whole part of the array is now sorted.
  - Now we will repeat the process for the right part [5, 2, 6, 4]
  - We can divide it into [5, 2] and [6, 4]
  - [5, 2] can be divided into [5] and [2]
  - Now we can merge [5] and [2] in sorted order to get [2, 5]
  - [6, 4] can be divided into [6] and [4]
  - Now we can merge [6] and [4] in sorted order to get [4, 6]
  - Now we have [2, 5] and [4, 6], we will merge them to get [2, 4, 5, 6]
  - The right whole part of the array is now sorted.
- After sorting both parts by breaking down again and again, we finally have 2 sorted halves: [1, 1, 2, 3, 4] and [2, 4, 5, 6].
- Now for the final time, we will merge these two halves to get the fully sorted array: [1, 1, 2, 2, 3, 4, 5, 6] by using two pointers method pointing to the start of each half and comparing the elements.
---
### Psuedo Code
- Let an array [3, 2, 4, 1, 3] where:
  - low points to the 0th index
  - high points to the last index

```c++
  void mergeSort(int arr[], int low, int high) {
    // Initially, low = 9, high = 4 from above example
    // The things which are happening are : Recursion and Backtracking
    // We are diving it in [3,2,4] and [1,3]
    // So low is 0 and high is 2 for the first half
    // And for the second half, low is 3 and high is 4
    // Base case - When the divided array is left with single element or practically `low = high`.

    // Base case:
    // For safety, we are checking for low > high too but it will be break when low == high!
    if(low >= high) {
      return;
    }

    int middleIndex = (low + high) / 2;
    // Left half
    mergeSort(arr, low, middleIndex); // Recursion for sorting left half
    // Right half
    mergeSort(arr, middleIndex + 1, high); // Recursion for sorting right half
    // Now we need to merge
    merge(arr, low, middleIndex, high);  // Merging the sorted halves from low to high    
  }
```
- Merge algorithm 
```cpp

  void merge(int &arr[], int low, int middleIndex, int high) {
    vector<int> merged;
    int left = low;
    int right = middleIndex + 1;
    while(left <= right && right <= high) {
      if (arr[left] < arr[right]) {
        merged.push_back(arr[left]);
        left++;
      } else {
        merged.push_back(arr[right]);
        right++;
      }
    }
    // If the above while loop ends, it means one of the halves is exhausted so we will add the remaining elements from the other half
    while (left <= middleIndex) {
      merged.push_back(arr[left]);
      left++;
    }
    while (right <= high) {
      merged.push_back(arr[right]);
      right++;
    }
    // Now we need to copy the merged elements back to the original array
    // First we will set the low pointer to 0 as merged array is starting from 0
    left = 0;
    for(auto it: merged) {
      arr[left] = it;
      left++;
    }
  }
```

- Time complexity of Merge Sort is O(n log n) [log base 2] in all cases (worst, average, and best) because it consistently divides the array in half and then merges the sorted halves.
- This is because lets say n is the size of the array
  - n gets divided by 2 in each step until we reach individual elements, resulting in log n (base2) divisions.
  - And we are performing merge operations for each level of division, which takes linear time O(n).
  - And it happens together division and merging at each level therefore the overall time complexity is O(n log n).