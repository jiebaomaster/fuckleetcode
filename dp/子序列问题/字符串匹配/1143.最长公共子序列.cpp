/**
 * https://leetcode-cn.com/problems/longest-common-subsequence/
 * https://labuladong.gitbook.io/algo/mu-lu-ye-2/mu-lu-ye-1/lcs
 * https://mp.weixin.qq.com/s/ZhPEchewfc03xWv9VP3msg
 * 设 dp[i][j] 为以 s1[i] 和 s2[j] 结尾的最长公共子序列长度，则
 * dp[i][j] = dp[i-1][j-1] + 1             s1[i]==s2[j] 
 *          = max{dp[i-1][j], dp[i][j-1]}  s1[i]!=s2[j]
 * 可以延长时就延长，不可延长时取前一部分的最大值
 */
class Solution {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    // dp 的第一行和第一列是初始状态，dp[i][j] 表示 s1[i-1] s2[j-1]
    vector<vector<int>> dp(text1.size() +1, vector<int>(text2.size() + 1));
    // [1,size] 遍历整个字符串
    for (int i = 1; i <= text1.size(); i++) {
      for (int j = 1; j <= text2.size(); j++) {
        if (text1[i - 1] == text2[j - 1]) // dp[i][j]=>s1[i-1],s2[j-1]
          dp[i][j] = dp[i - 1][j - 1] + 1;
        else
          dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
      }
    }

    return dp[text1.size()][text2.size()];
  }
};