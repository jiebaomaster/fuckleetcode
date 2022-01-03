/**
 * https://leetcode-cn.com/problems/coin-change-2/
 * https://labuladong.gitbook.io/algo/mu-lu-ye-2/mu-lu-ye-2/bei-bao-ling-qian
 * 将本题转换为背包问题的表述：有一个背包，最大容量为 amount，有一系列物品 coins，
 * 每个物品的重量为 coins[i]，每个物品的数量无限。请问有多少种方法，能够把背包恰好装满？
 * 
 * dp[i][j] 表示只使用前 i 个物品，恰好装入容量为 j 的背包的方法数
 * 对于每个物品 coins[i]，只有装入和不装入两种状态
 * 1. 如果不把第 i 个物品装入背包，那么恰好装满背包的方法数，
 *      取决于使用前面 i-1 个物品装满容量为 j 的背包的方法数，即 dp[i-1][j]
 * 2. 如果把第 i 个物品装入背包，那么恰好装满背包的方法数，
 *      取决于使用前面 i 个物品装满容量为 j-coins[i] 的背包的方法数，即 dp[i][j-coins[i]]。
 *     （本题为完全背包问题，每个物品数量无限，当使用了第i个物品后，还能再次使用）
 * 3. 当背包剩余空间不能装下第 i 个物品时，只能选择不装入物品 i 的情况
 */
class Solution {
 public:
  int change(int amount, vector<int>& coins) {
    vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1));
    for (int i = 0; i <= coins.size(); i++) dp[i][0] = 1;
    for (int j = 1; j <= amount; j++) dp[0][j] = 0;

    for (int i = 1; i <= coins.size(); i++) { // 遍历物品
      for (int j = 1; j <= amount; j++) { // 遍历背包容量
        if (j < coins[i - 1]) // 背包的剩余空间太小，当前物品不能装入
          dp[i][j] = dp[i - 1][j];
        else // 总的方法数为装入和不装入两种方法数之和
          dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
      }
    }
    return dp[coins.size()][amount];
  }
};

