/**
 * https://leetcode-cn.com/problems/search-in-rotated-sorted-array/
 * 
 * 有序的数组应想到用二分法
 * 本题相对于普通的二分法，收缩区间的方向判断更复杂，普通二分只有两种情况，这里有6种
 * 设 nums[k] = target，m = (l+r)/2
 * 1. nums[m] > targer，当 k 和 m 在一边时，r=m-1
 *      [  k   m        ]  r=m-1
 *      [  k   m  |     ]  r=m-1
 *      [         | k m ]  r=m-1
 *      [      m  | k   ]  l=m+1
 * 2. nums[m] < targer，当 k 和 m 在一边时，l=m+1
 *      [  m   k        ]  l=m+1
 *      [  m   k  |     ]  l=m+1
 *      [         | m k ]  l=m+1
 *      [  m      | k   ]  r=m-1
 * 通过和 nums[l]、nums[r] 的比较可判断某个元素在旋转的哪一边
 */
class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int m = (l + r) / 2;
      if (nums[m] == target)
        return m;
      else if (nums[m] > target) {
        // k 和 m 分别在旋转的两边
        if (nums[l] > target && nums[m] > nums[r])
          l = m + 1;
        else
          r = m - 1;
      } else {
        // k 和 m 分别在旋转的两边
        if (nums[m] < nums[l] && target > nums[r])
          r = m - 1;
        else
          l = m + 1;
      }
    }
    return -1;
  }
};