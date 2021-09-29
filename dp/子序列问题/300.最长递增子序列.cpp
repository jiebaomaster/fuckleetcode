/**
 * https://leetcode-cn.com/problems/longest-increasing-subsequence/
 * https://labuladong.gitbook.io/algo/mu-lu-ye-2/mu-lu-ye-1/dong-tai-gui-hua-she-ji-zui-chang-di-zeng-zi-xu-lie
 * f(i) 为以 nums[i] 结尾的最长递增子序列的长度，则
 * f(i) = max{f(j)+1, 1} 其中 0<=j<i 且 nums[j] < nums[i]
 * 从前面已算出的最长长度的子序列中挑选出满足递增的
 */
class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    vector<int> dp(nums.size(), 1);
    int res = 1;
    for (int i = 1; i < nums.size(); i++) {
      for (int j = 0; j < i; j++) {
        dp[i] = max(dp[i], nums[i] > nums[j] ? dp[j] + 1 : 1);
      }
      res = max(res, dp[i]);
    }
    return res;
  }
};