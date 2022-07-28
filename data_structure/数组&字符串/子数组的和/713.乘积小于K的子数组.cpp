/**
 * https://leetcode.cn/problems/subarray-product-less-than-k/
 * 一个长度为 n 的数组，他的所有连续子串数量是 1+2+...+n
 * 新增加元素 nums[r] 后，经左边界收缩后满足要求的子数组为 nums[l...r]，
 * 则新增的符合要求的子数组为包含 nums[r] 的那些，共 r-l+1 个
 */
class Solution {
 public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int l = 0, r = 0;
    int n = nums.size();
    int cur = 1;
    int res = 0;
    while (r < n) {
      cur *= nums[r++];
      while (l < r && cur >= k) {
        cur /= nums[l++];
      }
      res += r - l;
    }

    return res;
  }
};