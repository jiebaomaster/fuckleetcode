/**
 * https://leetcode-cn.com/problems/max-consecutive-ones-iii/
 * 经典滑动窗口，右边无脑滑动，左边看情况收缩
 */
class Solution {
 public:
  int longestOnes(vector<int>& nums, int k) {
    int l = 0, r = 0;
    int cnt0 = 0;
    int ret = 0;

    while (r < nums.size()) {
      if (nums[r] == 0) {
        cnt0++;
      }
      while (cnt0 > k) {
        if (nums[l] == 0) cnt0--;
        l++;
      }
      res = max(res, r - l + 1);
      r++;
    }

    return ret;
  }
};