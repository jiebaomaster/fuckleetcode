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

/**
 * 背包问题，常规思路
 * dp[i][j] 考虑不放入 nums[i] 和放入 nums[i] 两种情况，取最小值
 * 需要注意 dp 初始值
 */
class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1));

    // dp[i][0] = 0，装满容量为 0 的背包不需要任何物品
    for (int j = 1; j <= amount; j++) {
      dp[0][j] = 10050; // 足够大的值，代表不能被选择
    }
    for (int i = 1; i <= coins.size(); i++) {
      for (int j = 1; j <= amount; j++) {
        if (coins[i - 1] > j)
          dp[i][j] = dp[i - 1][j];
        else {
          dp[i][j] = min(dp[i - 1][j],                  // 不放入 nums[i]
                         dp[i][j - coins[i - 1]] + 1);  // 放入 nums[i]
        }
      }
    }

    return dp[coins.size()][amount] > amount ? -1 : dp[coins.size()][amount];
  }
};