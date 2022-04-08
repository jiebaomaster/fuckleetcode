/**
 * https://leetcode-cn.com/problems/minimum-size-subarray-sum/
 * 找出该数组中满足其和 ≥target 的长度最小的 连续子数组
 * 滑动窗口找出所有符合要求的窗口，返回最小的。
 * 由于数组中全是正数，滑动窗口只需遵循过小右扩，过大左缩
 */
class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int l = 0, r = 0;
    int cur = 0; // 当前滑动窗口中的值
    int res = INT_MAX;
    while (r < nums.size()) {
      cur += nums[r++];
      while (cur >= target) {
        res = min(res, r - l);
        cur -= nums[l++];
      }
    }
    return res == INT_MAX ? 0 : res;
  }
};