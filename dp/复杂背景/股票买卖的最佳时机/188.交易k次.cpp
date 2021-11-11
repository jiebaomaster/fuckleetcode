/**
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/
 * https://labuladong.gitee.io/algo/3/26/92/
 * 
 * 股票买卖问题的最基本类型
 * 
 * 这个问题的「状态」有三个，第一个是天数，第二个是允许交易的最大次数，第三个是当前的持有状态。
 * 设 dp[i][k][0 or 1] 为第 i 天时，最多交易次数为 k 时，在持有或不持有股票情况下，最多获得的利润。
 * 比如说 dp[3][2][1] 的含义就是：今天是第三天，我现在手上持有着股票，至今最多进行 2 次交易。
 * 显然在最后一天要获得最大利润，必须不持有股票，即 dp[n][k][0]
 * 
 * 对于股票来说，每天都有三种「选择」：买入、卖出、无操作
 * 1. 今天我没有持有股票，有两种可能，我从这两种可能中求最大利润：
 *    - 我昨天就没有持有，且截至昨天最大交易次数限制为 k；然后我今天选择 rest，
 *      所以我今天还是没有持有，最大交易次数限制依然为 k
 *    - 我昨天持有股票，且截至昨天最大交易次数限制为 k；但是今天我 sell 了，
 *      所以我今天没有持有股票了，最大交易次数限制依然为 k。
 *    即 dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
 *                     max( 今天选择 rest,        今天选择 sell       )
 * 2. 今天我持有着股票，最大交易次数限制为 k，那么对于昨天来说，有两种可能，我从这两种可能中求最大利润：
 *    - 我昨天就持有着股票，且截至昨天最大交易次数限制为 k；然后今天选择 rest，
 *      所以我今天还持有着股票，最大交易次数限制依然为 k。
 *    - 我昨天本没有持有，且截至昨天最大交易次数限制为 k - 1；但今天我选择 buy，
 *      所以今天我就持有股票了，最大交易次数限制为 k。
 *    即 dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
 *                     max( 今天选择 rest,         今天选择 buy         )
 * 
 * 注意：在 sell 的时候给 k 减小 1 和在 buy 的时候给 k 减小 1 不是等效的，
 *      因为交易是从 buy 开始，如果 buy 的选择不改变交易次数 k 的约束，会出现交易次数超出限制的错误。
 * 
 * 如果传入的 k 值非常大，会导致 dp 数组非常大，超过了内存限制。那么交易次数 k 最多有多大呢？
 * 一次交易由买入和卖出构成，至少需要两天。所以说有效的限制 k 应该不超过 n/2，如果超过，就没有约束作用了，
 * 相当于 k = +infinity，这种情况直接使用 122 题第解法即可。
 */
class Solution {
 public:
  int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    if (k > n / 2) return maxProfit_infinity(prices);

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

  int maxProfit_infinity(vector<int>& prices) {
    int profit = 0;
    for (int i = 1; i < prices.size(); i++) {
      if (prices[i - 1] < prices[i]) {
        profit += prices[i] - prices[i - 1];
      }
    }
    return profit;
  }
};