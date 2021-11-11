/**
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
 * https://labuladong.gitee.io/algo/3/26/92/
 */
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n <= 1) return 0; // 只有一天没法卖

    vector<vector<int>> dp(n, vector<int>(2));
    dp[0][0] = 0;
    dp[0][1] = -prices[0]; // 第 0 天未持有，买入第 0 天的股票
    dp[1][1] = max(-prices[0], -prices[1]); // 第 1 天持有，应该买入最便宜的股票
    dp[1][0] = max(0, prices[1] - prices[0]); // 第 1 天未持有，没交易或者交易了一次

    for (int i = 2; i < n; i++) {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
      // 每次 卖 完之后要等一天才能继续交易，则第 i 天选择 买 的时候，要从 i-2 的状态转移，而不是 i-1
      dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i]);
    }

    return dp[n - 1][0];
  }
};