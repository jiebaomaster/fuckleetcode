/**
 * https://leetcode-cn.com/problems/coin-change/
 * https://labuladong.gitbook.io/algo/mu-lu-ye-2/mu-lu-ye/dong-tai-gui-hua-xiang-jie-jin-jie#er-cou-ling-qian-wen-ti
 * 凑整数
 * f(n) 为整数 n 最小需要几个硬币，则可知:
 * f(n) = min{f(n - c) | c:coins} + 1, n > 0
 * 即去掉最后一个加入的硬币面额，最优子结构+1
 */
class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    int dp[10050] = {0}; 
    vector<int> mins(coins.size()); // 记录每次产生的最小值
    for (int i = 1; i <= amount; i++) {
      for (int j = 0; j < coins.size(); j++) {
        // 负数代表不可能的子问题，用一个不可能取到的数表示不可能的情况
        if (i - coins[j] < 0)
          mins[j] = amount + 1; 
        else
          mins[j] = dp[i - coins[j]];
      }
      dp[i] = *min_element(mins.begin(), mins.end()) + 1;
    }
    // 最终结果是不可能的情况时要返回 -1
    return dp[amount] >= amount + 1 ? -1 : dp[amount];
  }
};