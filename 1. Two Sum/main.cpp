#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;
    int n = nums.size();

    /*
    O(n) to initialize hash map
    */
    for (int i = 0; i < n; ++i) {
      mp[target - nums[i]] = i;
    }

    int val;
    /*
    O(n) to search hash map
    */
    for (int i = 0; i < n; ++i) {
      auto it = mp.find(nums[i]);
      if (it != mp.end()) {
        val = it->second;
        if (i != val) {
          return {i, val};
        }
      }
    }

    return {0, 1};
  }
};

/*
Approach: Hash Map
Total time complexity: O(n) + O(n) = 2*O(n) ~ O(n)
*/