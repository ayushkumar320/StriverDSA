#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  void merge(vector<int> &arr, int low, int mid, int high)
  {
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
    {
      if (arr[left] <= arr[right])
      {
        temp.push_back(arr[left]);
        left++;
      }
      else
      {
        temp.push_back(arr[right]);
        right++;
      }
    }

    while (left <= mid)
    {
      temp.push_back(arr[left]);
      left++;
    }

    while (right <= high)
    {
      temp.push_back(arr[right]);
      right++;
    }

    for (int i = 0; i < temp.size(); i++)
    {
      arr[low + i] = temp[i];
    }
  }

  void sort(vector<int> &arr, int low, int high)
  {
    if (low >= high)
    {
      return;
    }
    int mid = low + (high - low) / 2; // More robust way to find mid
    sort(arr, low, mid);
    sort(arr, mid + 1, high);
    merge(arr, low, mid, high);
  }

  vector<int> mergeSort(vector<int> &nums)
  {
    sort(nums, 0, nums.size() - 1);
    return nums;
  }
};