/**
 * https://leetcode-cn.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
 * https://leetcode-cn.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/solution/rang-zi-fu-chuan-cheng-wei-hui-wen-chuan-de-zui--2/
 * https://labuladong.gitee.io/algo/3/26/95/
 * 
 * 状态：
 *  回文是字符串的某种属性，需要对称地考虑最前端和最后端，可以考虑区间 DP
 *  dp[i][j] 表示对于 s 的子串 s[i..j]，使其变为回文串所需的最少添加字符数量
 * 选择：
 *  1. 如果 s[i]==s[j]，那么最外层已经形成了回文，我们只需要使得 s[i+1..j-1] 是回文
 *     即 dp[i][j] = dp[i+1][j-1]
 *  2. 如果 s[i]!=s[j]，那么我们要么在 s[i..j] 的末尾添加字符 s[i]，此时 s[i+1..j] 必须是回文；
 *     要么在 s[i..j] 的开头添加字符 s[j]，此时 s[i..j-1] 必须是回文
 *     即 dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1
 */
class Solution {
 public:
  int minInsertions(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n));

    for (int i = n - 1; i >= 0; i--) {
      for (int j = i + 1; j < n; j++) {
        if (s[i] == s[j])
          dp[i][j] = dp[i + 1][j - 1];
        else
          dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
      }
    }

    return dp[0][n - 1];
  }
};