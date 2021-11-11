/**
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/
 * 
 * 这一题可以看作是股票买卖问题的特殊情况，也可以直接从题目要求出发求解。
 * 
 * 直接考虑问题，可以使用 贪心算法。由于不限制交易次数，只要今天股价比昨天高，就交易。
 * 需要注意的是，贪心算法计算的过程并不是真正交易的过程。
 * 举例来说：
 * [7, 1, 5, 6] 第二天买入，第四天卖出，收益最大（6-1），所以一般人可能会想，怎么判断不是第三天就卖出了呢? 
 * 这里就把问题复杂化了，根据题目的意思，当天卖出以后，当天还可以买入，所以其实可以第三天卖出，第三天买入，
 * 第四天又卖出（（5-1）+ （6-5） === 6 - 1）。所以算法可以直接简化为只要今天比昨天大，就卖出。
 */
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int profit = 0;
    for (int i = 1; i < prices.size(); i++) {
      if (prices[i - 1] < prices[i]) {
        profit += prices[i] - prices[i - 1];
      }
    }
    return profit;
  }
};

/**
 * 看作是股票买卖问题的特殊情况：不限制交易次数，即k为无穷大，此时 k == k-1
 * dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
 * dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
 *             = max(dp[i-1][k][1], dp[i-1][k][0] - prices[i])
 * 
 * 我们发现数组中的 k 已经不会改变了，也就是说不需要记录 k 这个状态了：
 * dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
 * dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])
 */
class Solution1 {
 public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2));
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    for (int i = 1; i < n; i++) {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
    }

    return dp[n - 1][0];
  }
};