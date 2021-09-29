/**
 * https://leetcode-cn.com/problems/delete-operation-for-two-strings/
 * https://labuladong.gitbook.io/algo/mu-lu-ye-2/mu-lu-ye-1/lcs
 * https://mp.weixin.qq.com/s/ZhPEchewfc03xWv9VP3msg
 * 给定两个字符串，分别删除若干字符之后使得两个字符串相同，则剩下的字符为两个字符串的公共子序列。
 * 为了使删除操作的次数最少，剩下的字符应尽可能多。当剩下的字符为两个字符串的最长公共子序列时，
 * 删除操作的次数最少。则本题可以转化为求最长公共子序列的长度
 */
class Solution {
 public:
  int minDistance(string word1, string word2) {
    int len1 = word1.size(), len2 = word2.size();
    int len_lcs = longestCommonSubsequence(word1, word2); // 求最长公共子序列长度
    return len1 - len_lcs + len2 - len_lcs; // 求删除的字符串长度，此时删除的长度最小
  }

int longestCommonSubsequence(string &text1, string &text2) {
    // dp 的第一行和第一列是初始状态，dp[i][j] 表示 s1[i-1] s2[j-1]
    vector<vector<int>> dp(text1.size() +1, vector<int>(text2.size() + 1));
    int res = 0;
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