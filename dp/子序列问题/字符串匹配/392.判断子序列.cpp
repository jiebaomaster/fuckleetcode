/**
 * https://leetcode.cn/problems/is-subsequence/
 * 判断 s 是否为 t 的子序列
 * 方法一：字符串匹配 dp，第 72 题编辑距离的基本题，只能删除
 * dp[i][j] 为 s[i] 是否是 t[j] 的子序列
 * 1. s[i] != t[j] 时，一对字符匹配不成功，s[i] 要往前匹配
 * 2. s[i] == t[j] 时，一对字符匹配成功，s[i] 既可以往前匹配也可以就地匹配
 */
class Solution {
 public:
  bool isSubsequence(string s, string t) {
    int n = s.size();
    int m = t.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
    for (int i = 0; i <= m; i++) {
      dp[0][i] = true;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (s[i - 1] == t[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] || dp[i][j - 1];
        } else {
          dp[i][j] = dp[i][j - 1];
        }
      }
    }
    return dp[n][m];
  }
};

/**
 * 方法二：双指针
 */
class Solution {
 public:
  bool isSubsequence(string s, string t) {
    int n = s.length(), m = t.length();
    int i = 0, j = 0;
    while (i < n && j < m) {
      if (s[i] == t[j]) {
        i++;
      }
      j++;
    }
    return i == n; // 匹配成功的话，最后 i 到达 s 的末尾
  }
};
