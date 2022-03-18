/**
 * https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray/
 * 类似最长公共子序列，区别在于子树组是连续的
 * 则 nums1[i] 和 nums2[j] 不想等时 dp[i][j] 必为 0
 */
class Solution {
 public:
  int findLength(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    int ret = -1;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (nums1[i - 1] == nums2[j - 1]) 
          dp[i][j] = dp[i - 1][j - 1] + 1;
        ret = max(ret, dp[i][j]);
      }
    }
    return ret;
  }
};