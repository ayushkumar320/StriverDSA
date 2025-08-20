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