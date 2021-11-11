/**
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
 * https://labuladong.gitee.io/algo/3/26/92/
 */
class Solution {
 public:
  int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2));
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    for (int i = 1; i < n; i++) {
      // 每次交易要支付手续费，只要把手续费从利润中减去即可。
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
    }

    return dp[n - 1][0];
  }
};