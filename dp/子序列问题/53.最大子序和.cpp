/**
 * https://leetcode-cn.com/problems/maximum-subarray/
 * https://labuladong.gitbook.io/algo/mu-lu-ye-2/mu-lu-ye-1/zui-da-zi-shu-zu
 * f(i) 为以 nums[i] 结尾的最大连续子序列和，则
 * f(i) = max{f(i-1), 0} + nums[i]
 * f(i) 的状态只与 f(i-1) 有关，所以只需要保存 f(i-1) 即可，不需要保证整个状态数组
 */
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int dp_pre = nums[0];
    int dp_cur;
    int res = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      dp_cur = dp_pre > 0 ? dp_pre + nums[i] : nums[i];
      res = max(res, dp_cur);
      dp_pre = dp_cur;
    }
    return res;
  }
};