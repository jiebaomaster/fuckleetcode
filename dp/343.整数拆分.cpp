/**
 * https://leetcode.cn/problems/integer-break/
 * 方法一：回溯
 * 把所有组合都求出来，再求最大值，会超时
 */
class Solution {
 public:
  int res;
  int integerBreak(int n) {
    vector<int> track;
    dfs(1, n, 0, 1, track);
    return res;
  }
  void dfs(int cur, int n, int sum, int multi, vector<int>& track) {
    if (cur == n || sum >= n) {
      if (sum == n && res < multi) {
        res = multi;
      }
      return;
    }

    if (sum + cur <= n) {
      track.push_back(cur);
      dfs(cur, n, sum + cur, multi * cur, track);
      track.pop_back();
    }

    dfs(cur + 1, n, sum, multi, track);
  }
};

/**
 * 方法二：dp
 * dp[i] 表示将正整数 i 拆分成至少两个正整数的和之后，这些正整数的最大乘积
 * 假设对正整数 i 拆分出的第一个正整数是 j（1≤j<i），则有以下两种方案：
 * 将 i 拆分成 j 和 i-j 的和，且 i-j 不再拆分成多个正整数，此时的乘积是 j×(i−j)；
 * 将 i 拆分成 j 和 i-j 的和，且 i-j 继续拆分成多个正整数，此时的乘积是 j×dp[i−j]。
 */
class Solution {
 public:
  int integerBreak(int n) {
    vector<int> dp(n + 1);
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
      for (int j = 1; j < i; j++) {
        dp[i] = max(dp[i], max(j * dp[i - j], j * (i - j)));
      }
    }
    return dp[n];
  }
};