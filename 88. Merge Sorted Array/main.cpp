#include <vector>
using namespace std;

class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int a = m - 1, b = n - 1, i = m + n - 1;

    /*
    Time complexity: O(m + n)
    Description: Each loop iteration, either a or b will decrease; a can only decrease m times before becoming less than zero and b can only decrease n times
    */
    while (a >= 0 && b >= 0) {
      if (nums1[a] > nums2[b]) {
        nums1[i--] = nums1[a--];
      } else {
        nums1[i--] = nums2[b--];
      }
    }
    while (a >= 0) {
      nums1[i--] = nums1[a--];
    }
    while (b >= 0) {
      nums1[i--] = nums2[b--];
    }
  }
};

/*
Overall time complexity: O(m + n)
*/