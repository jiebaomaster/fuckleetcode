/**
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
 * 
 * 这一题可以看作是股票买卖问题的特殊情况，也可以直接从题目要求出发求解。
 * 
 * 如果直接考虑：
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/121-mai-mai-gu-piao-de-zui-jia-shi-ji-by-leetcode-/
 * 随着时间的推移，每天都可以选择出售股票与否。那么遍历所有在第 i 天卖股票的情况，就能求出最多赚多少钱了。
 * 显然，想要利益最大化肯定想在历史最低点买的股票。我们需要用一个变量记录一个历史最低价格 minprice，
 * 假设自己的股票是在那天买的。那么我们在第 i 天卖出股票能得到的利润就是 prices[i] - minprice。
 * 因此，我们只需要遍历价格数组一遍，记录历史最低点，然后在每一天考虑这么一个问题：如果我是在历史最低点买进的，
 * 那么我今天卖出能赚多少钱？当考虑完所有天数之时，我们就得到了最好的答案。
 */
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int minprice = prices[0];
    int maxprofit = 0;
    for (auto e : prices) {
      minprice = min(e, minprice);
      maxprofit = max(maxprofit, e - minprice);
    }
    return maxprofit;
  }
};

/**
 * 看作是股票买卖问题的特殊情况：代入 k=1
 * 
 * dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][1][1] + prices[i])
 * dp[i][1][1] = max(dp[i-1][1][1], dp[i-1][0][0] - prices[i]) 
 *             = max(dp[i-1][1][1], -prices[i])
 * 解释：k = 0 的 base case，所以 dp[i-1][0][0] = 0。
 * 现在发现 k 都是 1，不会改变，即 k 对状态转移已经没有影响了。进行进一步化简去掉所有 k：
 * dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
 * dp[i][1] = max(dp[i-1][1], -prices[i])
 */
class Solution1 {
 public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2));
    dp[0][1] = -prices[0];
    for (int i = 1; i <= n; i++) {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i - 1]);
      dp[i][1] = max(dp[i - 1][1], -prices[i - 1]);
    }
    return dp[n][0];
  }
};