/**
 * https://leetcode-cn.com/problems/dungeon-game/
 * https://labuladong.gitee.io/algo/3/24/80/
 * 这道题一眼就能看出来用动态规划解，关键是dp的顺序，这道题的dp是倒序的。
 * 1. 如果使用正序 dp，则 dp[i][j] 表示“从起点出发，到达位置（i，j）所需要的最少血量”，
 *    即使我们知道了 上dp[i-1][j] 和 左dp[i][j-1]，我们也不能根据哪个耗血量小就挑哪个。
 *    因为有可能 dp[i-1][j] 处的耗血量大，但该处的剩余血量也大，当 dp[i][j] 甚至更深处
 *    dp[i+1][j+1] 是减血操作，选dp[i-1][j]可能才是全局最优。剩余血量是无法得知的状态。
 * 2. 如果使用倒序 dp，则 dp[i][j] 表示“从（i，j）出发，到达终点需要最少的血量”，
 *    如果我们知道了 下dp[i+1][j] 和 右dp[i][j+1]，显然应该选他们中耗血量最小的那条路
 * 
 * 为什么不能像【最小路径和】一样是正序的？因为【最小路径和】是无状态的，你会发现【最小路径和】
 * 倒序 dp 也是可以的，这道题由于有“加血”的过程，只能依赖后面的值判断需要的血量。
 * 
 * 状态转移方程：
 * 1. 如果 dungeon[i][j] 是(负数)减血，则需要的血量增多 “-dungeon[i][j]”
 *    dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]
 * 2. 如果 dungeon[i][j] 是(正数)加血，则需要的血量减少 “dungeon[i][j]”，
 *    且耗血量减少到小于等于0时，因为生命值必须大于 0，耗血量应该为 1
 *    tmp = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
 *    dp[i][j] = tmp <= 0 ? 1 : tmp;
 */
class Solution {
 public:
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int m = dungeon.size();
    int n = dungeon[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    // base case
    for (int i = 0; i < m; i++) dp[i][n] = INT_MAX;
    for (int j = 0; j < n; j++) dp[m][j] = INT_MAX;
    dp[m - 1][n] = dp[m][n - 1] = 1;
    // 倒序dp，从终点出发，遍历到起点
    for (int i = m - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        int res = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
        dp[i][j] = res <= 0 ? 1 : res;
      }
    }
    return dp[0][0]; // 结果为起点的dp值
  }
};