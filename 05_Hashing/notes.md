# Hashing
- It is used to count the frequency of elements in a collection.
- It is used to find duplicates in an array.
- It is used to find the first non-repeating character in a string.
- It is used to group anagrams together.

## Basic approaches to count
- Iterating over the array using `Loops` and updating the counter when it encounters an element.
- Basic example:
  ```cpp
  int f(int number, int a[]) {
    int counter = 0;
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
      if (a[i] == number) {
        counter++;
      }
    }
    return counter;
  }
  ```
  - We are running the loop for n times, therefore the time complexity is `O(n)` for each number check.
  - Now suppose there are n numbers in array `a[]` and we want to count the frequency of each number then loop will run `O(n^2)` times in total where now n is the number of distinct elements in the array to count the frequency.
  - This is not efficient for large arrays.

- Since the above way for counting can be very time consuming, to get over this, we use concept of hashing

## Hashing Working

- We will create a new array (hash array) of size `n+1` where `n` is the number of distinct numbers in the array whose frequency we want to count.
- In that hash array, we will store the frequency of each number.
- Initially every element of the hash array will be 0.

---

- Now let suppose we have an array `a[]` with elements `{1, 2, 2, 3, 3, 3}`.
- We will create a hash array `hash[]` of size `4` (since the maximum element is `3`) and initialize all elements to `0`.
- We will iterate over the original array `a[]` and for each element `x`, we will increment `hash[x]` by `1` that means the frequency of 1 can be deduced from index 1 of `hash[]`.
- After processing the array, the hash array will contain the frequency of each element.
- Now if I want to check the frequency of `2`, I will simply call `hash[2]`.

---

## Some key takeaways
- When we are inside main, we can not declare array of size more than 10^6, if we try to declare any larger array in main than `arr[1e6]`, we will get `Segmentation error`.
- To overcome this, we can declare `globally` if the size is somewhere around `1e7` (integer).
- The time complexity of hashing is `O(n)` for building the hash table and `O(1)` for each query.

# Character Hashing
- We can use a similar approach for characters as we did for integers.
- We can create a hash array of size `256` (for all ASCII characters) and use it to count the frequency of each character in a string.

- Example:
  - S = "abcdabefc"
  - We can create a hash array `hash[256]` and initialize it to `0`.
  - We will iterate over the string `S` and for each character `c`, we will increment `hash[c]` by `1`.
  - After processing the string, the hash array will contain the frequency of each character.

### Code snippet: 
- Using loop: 
  ```cpp
  int f(char c, char S[]) {
    int counter = 0;
    for (int i = 0; i < strlen(S); i++) {
      if (S[i] == c) {
        counter++;
      }
    }
    return counter;
  }
  ```
- Using hashing:
  ```cpp
  int f(char c, char S[]) {
    int hash[256] = {0};
    for (int i = 0; i < strlen(S); i++) {
      hash[S[i]]++;
    }
    return hash[c];
  }
  ```
- The time complexity of hashing is `O(n)` for building the hash table and `O(1)` for each query.

# Tools for hashing (STL)
- With the use of STLs and Collection in C++, we can implement hashing more easily and efficiently.
- Time space complexity of maps in all the best, worst and average case scenario is O(log(N)) where N is the number of element

- `unordered_map`: A hash table implementation in C++ that allows for fast key-value pair storage and retrieval.
- `unordered_set`: A hash table implementation for storing unique elements with fast access.
- `vector`: While not a hash table, it can be used in conjunction with hashing techniques for efficient data storage and retrieval.

# Collection used in hashing
- `hash_map`: A hash table implementation for storing key-value pairs.
- `hash_set`: A hash table implementation for storing unique elements.

## Map and unordered map
- Map is a data structure in C++ that stores key-value pairs in a sorted order.
- Unordered map is a data structure in C++ that stores key-value pairs in an unsorted order, allowing for faster access times on average.

### Example and usecase of map
  - Suppose we have a given array `a[]` with elements `{1, 2, 2, 3, 3, 3}`.
  - We can use a map to count the frequency of each element in the array.
  - The key will be the element itself, and the value will be its frequency.

  ```cpp
  // mpp[arr[i]]++
  // If numbers are bigger, we can use map<long, long>
  #include <iostream>
  #include <map>
  using namespace std;

  int main() {
      int a[] = {1, 2, 2, 3, 3, 3};
      map<int, int> freqMap;

      for (int i = 0; i < 6; i++) {
          freqMap[a[i]]++;
      }

      // Display the frequency of each element
      for (auto it = freqMap.begin(); it != freqMap.end(); it++) {
          cout << "Element: " << it->first << ", Frequency: " << it->second << endl;
      }

      return 0;
  }
  ```