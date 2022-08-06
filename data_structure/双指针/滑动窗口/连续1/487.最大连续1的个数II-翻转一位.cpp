/**
 * https://leetcode.cn/problems/max-consecutive-ones-ii/
 *
 */
class Solution {
 public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int l = 0, r = 0;
    int n = nums.size();
    int zero = -1; // 记录第一个 0 的位置
    int res = 0;
    while (r < n) {
      if (nums[r] == 1) { // 1，更新最大值
        res = max(res, r - l + 1);
      } else { // 0，选择翻转或左边界收缩到第一个 0 的后一位
        l = zero + 1;
        res = max(res, r - l + 1);
        zero = r;
      }
      r++;
    }
    return res;
  }
};