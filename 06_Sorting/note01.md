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

# Quick Sort
- Quick Sort is a divide-and-conquer algorithm that sorts an array by partitioning it into smaller sub-arrays.
- The basic idea is to select a 'pivot' element from the array and partition the other elements into two sub-arrays according to whether they are less than or greater than the pivot. Pivot element can be any element from the array.
- Now we pick up the pivot, and place it at its correct place. 
- Now we choose the next element and will place them at their respective correct place.
- Smaller on the left, larger on the right.
- After placing the pivot on correct place, iterate the remaining elements and larger elements are placed in right of the pivot element and smaller elements are placed in left of the pivot element.
- After 1st step, the pivot is in its final position, and the array is partitioned into two sub-arrays.
- The process is then repeated recursively for the sub-arrays.

### Algorithm
- We will use concept of low and high and pointers to compare the elements.

- Suppose we have an array `a[]` 
  ```[4, 6, 2, 5, 7, 9, 1, 3]```
  - The low variable points to the 0th index i.e `a[0]`.
  - The high variable points to the last index i.e. `a[7]`.
  - Let pivot variable point to `a[low]`.
- Next step is placing the pivot element on right place.
  - This can be done by finding the first element which is greater than pivot i.e. `a[low]`.
  - Here 6 (the second element) is greater than 4 (the pivot), so we will assign a new pointer i (starting from left) which points to the element 6.
  - Now we will use another pointer j (starting from right/last) to find the first element which is smaller than pivot i.e. `a[low]`.
  - Here the last element 3 is smaller than 4 (the pivot), so we will assign a new pointer j which points to the element 3.
  - Now we will swap the elements at i and j.
  - New array : ```[4, 3, 2, 5, 7, 9, 1, 6]```
- Again we will figure out the first element from left which is greater than pivot, here 5 (the fourth element).
  - So we will move the pointer i to point to 5.
  - Now we will figure out the first element from right which is smaller than pivot, here 1 (the seventh element).
  - So we will swap the elements at i and j.
  - Now new array formed is: ```[4, 3, 2, 1, 7, 9, 5, 6]```
- The above process is repeated until the left part becomes the territory where every element is smaller than pivot
- New array: ```[1, 3, 2, 4, 7, 8, 5, 6]```
- Now this element 4 is termed as partition index and 2 new sub-arrays are formed from (low to partition - 1) and other (partition + 1 to high)
- We perform quick sort on both sub-arrays.

### Pseudo Code
```cpp
  
  int partition(int &arr[], int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i < j) {
      // Finding first element greater than pivot
      // For cases where multiple elements are equal to pivot, here we have decided to place it on the left part se arr[i] <= pivot is considered, in case if we wanted to place it on the right we could have included equality with the >= part i.e with the next while loop
      while (arr[i] <= pivot && i <= high - 1) {
        i++;
      }
      // Finding first element smaller than pivot
      while (arr[j] > pivot && j >= low + 1) {
        j--;
      }
      // As j crosses i, we are already in the correct halves
      if (i < j) {
        swap(arr[i], arr[j]);
      }
    }
    // Swapping the pivot to the correct place
    swap(arr[low], arr[j]);
    // Return the partition (here pivot got swapped with arr[j] which means j is the correct position)
    return j;
  }
  
  
  void quickSort(int &arr[], int low, int high) {
    if (low < high) {
      int partitionIndex =  partition(arr, low, high);
      quickSort(arr, low, partitionIndex - 1);  // Recursion for left half
      quickSort(arr, partitionIndex + 1, high);  // Recursion for right half
    }
  }
```