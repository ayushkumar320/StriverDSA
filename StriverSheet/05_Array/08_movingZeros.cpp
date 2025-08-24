#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  vector<int> mz(vector<int> &arr)
  {
    int n = arr.size();
    // Finding the first
    int j = -1;
    for (int i = 0; i < n; i++)
    {
      if (arr[i] == 0)
      {
        j = i;
        break;
      }
    }
    if (j == -1)
      return arr;
    // Placing zeros to end
    for (int i = j + 1; i < n; i++)
    {
      if (arr[i] != 0)
      {
        swap(arr[i], arr[j]);
        j++;
      }
    }
    return arr;
  }
  void moveZeroes(vector<int> &nums)
  {
    nums = mz(nums);
  }
};