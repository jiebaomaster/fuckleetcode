/**
 * https://leetcode-cn.com/problems/max-consecutive-ones/
 * 给定一个二进制数组 nums，计算其中最大连续 1 的个数。
 * 双指针，遇到 0 则更新一次
 */
class Solution {
 public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int l = 0, r = 0;
    int ret = 0;
    while (r < nums.size()) {
      if (nums[r] == 0) {
        l = r+1;
      }
      ret = max(ret, r - l + 1);
      r++;
    }
    return ret;
  }
};