/**
 * https://leetcode-cn.com/problems/maximum-subarray/
 * https://labuladong.gitbook.io/algo/mu-lu-ye-2/mu-lu-ye-1/zui-da-zi-shu-zu
 * f(i) 为以 nums[i] 结尾的最大连续子数组和，则
 * f(i) = max{f(i-1), 0} + nums[i]
 * f(i) 的状态只与 f(i-1) 有关，所以只需要保存 f(i-1)
 * 即可，不需要保证整个状态数组
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

/**
 * 推广：返回求得的最大连续子数组
 */
class Solution1 {
 public:
  pair<int, int> maxSubArray(vector<int>& nums) {
    vector<int> dp(nums.size() + 1);
    int ret = INT_MIN;
    pair<int, int> maxlr; // 最大的连续子数组     
    pair<int, int> curlr; // 当前的连续子数组
    for (int i = 1; i <= nums.size(); i++) {
      if (dp[i - 1] < 0) {
        dp[i] = nums[i - 1];
        // 前面的连续子数组和为负数，则从新的起点开始记录
        curlr.first = i - 1;
        curlr.second = i - 1;
      } else {
        dp[i] = nums[i - 1] + dp[i - 1];
        curlr.second = i - 1; // 子数组向右扩张
      }

      if (dp[i] > ret) {
        ret = dp[i];
        // 遇到当前最大的连续子数组，记录
        maxlr.first = curlr.first;
        maxlr.second = curlr.second;
      }
    }
    return maxlr;
  }
};