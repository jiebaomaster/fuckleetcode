/**
 * https://leetcode-cn.com/problems/minimum-ascii-delete-sum-for-two-strings/
 * https://leetcode-cn.com/problems/minimum-ascii-delete-sum-for-two-strings/solution/huo-qu-zui-chang-gong-gong-zi-xu-lie-bia-514o/
 * 因为总编码是一定的，留下的越大删除的越小。题目要求删除字符的 ASCII 值的最小，
 * 则只要留下的字符串 ASCII 值最大，即题目转化成求两个字符串的 ASCII 值最大的公共子序列
 */
class Solution {
 public:
  int minimumDeleteSum(string s1, string s2) {
    int sum = 0; // 先把原先 ASCII 的总和求出来
    for (auto c : s1) sum += c;
    for (auto c : s2) sum += c;

    vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1));
    for (int i = 1; i <= s1.size(); i++) {
      for (int j = 1; j <= s2.size(); j++) {
        if (s1[i - 1] == s2[j - 1]) // 子序列问题，加入子序列
          dp[i][j] = dp[i - 1][j - 1] + s1[i - 1];
        else // 不能加入子序列的，取 ASCII 值最大的
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }

    return sum - dp[s1.size()][s2.size()] * 2; // 做差求删除的 ASCII 值
  }
};