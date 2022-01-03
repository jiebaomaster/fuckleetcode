/**
 * https://leetcode-cn.com/problems/last-stone-weight-ii/
 * https://leetcode-cn.com/problems/last-stone-weight-ii/solution/gong-shui-san-xie-xiang-jie-wei-he-neng-jgxik/
 * 本题的关键在于如何转化成背包问题：
 * 由引文中的分析可知最终的结果可以使用「为 stones 数组中的数字添加 +/- 符号，形成的“计算表达式”」所表示。
 * 问题转换为：为 stones 中的每个数字添加 +/-，使得形成的「计算表达式」结果绝对值最小。
 * 与（题解）494.目标和 类似，需要考虑正负号两边时，其实只需要考虑一边就可以了，
 * 使用总和 sum 减去一边能得到另外一边。
 * 由于想要「计算表达式」结果绝对值，因此需要将石子划分为差值最小的两个堆，
 * 要想两个堆差值最小，需要两个堆总和尽量相等，即需要每一堆的总和都尽量接近 sum/2
 * 问题彻底切换为 01 背包问题：从 stones 数组中选择，求选出数的总和不超过 sum/2 的最大值。
 * 
 * dp[i][j] 为使用前 i 个石头，“可以”装入容量为 j 的背包的最大重量
 * 则 dp[i][j] 为
 *   不装入第 i 个石头 dp[i - 1][j]
 *   装入第 i 个石头 dp[i - 1][j - stones[i]] + stones[i]
 * 中的最大值
 */
class Solution {
 public:
  int lastStoneWeightII(vector<int>& stones) {
    int sum = accumulate(stones.begin(), stones.end(), 0);
    int target = sum / 2;
    vector<vector<int>> dp(stones.size() + 1, vector<int>(target + 1));

    for (int i = 1; i <= stones.size(); i++) {
      for (int j = 1; j <= target; j++) {
        if (j < stones[i - 1])
          dp[i][j] = dp[i - 1][j];
        else
          dp[i][j] =
              max(dp[i - 1][j], dp[i - 1][j - stones[i - 1]] + stones[i - 1]);
      }
    }
    // 结果为 更大的一堆 - 更小的一堆
    return sum - dp[stones.size()][target] - dp[stones.size()][target];
  }
};