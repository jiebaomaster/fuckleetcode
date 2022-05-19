/**
 * https://leetcode.cn/problems/distinct-subsequences/
 * 
 * 字符串匹配 dp，第 72 题编辑距离的基本题，只能删除
 * dp[i][j] 为 t[i] 在 s[j] 的子序列中出现的次数
 * 1. s[i] != t[j] 时，匹配不成功，s[i] 不能用于匹配了，往前寻找 dp[i][j-1]
 * 2. s[i] == t[j] 时，匹配成功，s[i] 既可以往前匹配也可以就地匹配
 */
class Solution {
 public:
  int numDistinct(string s, string t) {
    int m = t.size();
    int n = s.size();
    // dp[i][j] 为 t[i] 在 s[j] 的子序列中出现的次数
    vector<vector<uint64_t>> dp(m + 1, vector<uint64_t>(n + 1));
    for (int i = 0; i <= n; i++) dp[0][i] = 1;

    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (s[j - 1] == t[i - 1])
          dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
        else
          dp[i][j] = dp[i][j - 1];
      }
    }
    return dp[m][n];
  }
};