/**
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/
 * 
 * 第 188 题的特殊情况，代入 k=2 即可
 */
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int k = 2;
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1,
                                   vector<vector<int>>(k + 1, vector<int>(2)));

    for (int j = 0; j <= k; j++)  // 还没开始的时候，是不可能持有股票的。
      dp[0][j][1] = INT_MIN;
    for (int i = 0; i <= n; i++)  // 不允许交易的情况下，是不可能持有股票的
      dp[i][0][1] = INT_MIN;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= k; j++) {
        dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i - 1]);
        dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i - 1]);
      }
    }
    return dp[n][k][0];
  }
};