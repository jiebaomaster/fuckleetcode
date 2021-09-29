/**
 * https://leetcode-cn.com/problems/longest-palindromic-subsequence/
 * https://mp.weixin.qq.com/s/zNai1pzXHeB2tQE6AdOXTA
 * dp 数组的定义是：在子串s[i..j]中，最长回文子序列的长度为dp[i][j]
 * dp[i][j] = dp[i + 1][j - 1] + 2                        ,s[i] == s[j]
 *          = dp[i][j] = max(dp[i + 1][j], dp[i][j - 1])  ,s[i] != s[j]
 * 1. 如果s[i] s[j]相等，那么它俩加上 s[i+1..j-1] 中的最长回文子序列就是 s[i..j] 的最长回文子序列
 * 2. 如果s[i] s[j]不相等，说明它俩不可能同时出现在 s[i..j] 的最长回文子序列中，
 *    那么把它俩分别加入 s[i+1..j-1] 中，看看哪个子串产生的回文子序列更长即可
 * 
 * 本题需要注意递推顺序问题，想求dp[i][j]需要知道dp[i+1][j-1]，dp[i+1][j]，dp[i][j-1]这三个位置
 * 即每次计算 dp[i][j] 时，左、下、左下三个方向的位置需要已知，只能斜着遍历或者反着遍历（先求i+1）：
 *            —— ——
 *    [i,j-1]｜ ｜*｜[i,j]
 *            —— ——
 * [i+1,j-1] ｜ ｜ ｜[i+1,j]
 *            —— ——
 */
class Solution {
 public:
  int longestPalindromeSubseq(string s) {
    vector<vector<int>> dp(s.size(), vector<int>(s.size()));
    int res = 1;
    // 初始化，i==j时长度为1的子序列肯定为回文
    for (int i = 0; i < s.size(); i++) dp[i][i] = 1;

    for (int i = s.size() - 1; i >= 0; i--) { // 反向遍历确保i+1先被计算出来
      for (int j = i + 1; j < s.size(); j++) { // i==j时dp=1，i>j时dp=0
        if (s[i] == s[j])
          dp[i][j] = dp[i + 1][j - 1] + 2;
        else
          dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
        res = max(res, dp[i][j]);
      }
    }

    return res;
  }
};