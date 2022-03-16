/**
 * https://leetcode-cn.com/problems/minimum-path-sum/
 * https://labuladong.gitee.io/algo/3/24/79/
 * dp[i][j] 为从点[0,0]到[i][j]的最小路径和
 * 则 dp[i][j] 的状态由左边和上边两个点的状态决定
 * dp[i][j] = grid[i][j] + min{dp[i - 1][j]  左
 *                             dp[i][j - 1]} 上
 * 
 * 这道题如果要问具体的路径，只能使用二维 dp，
 * 在 dp 数组中从右下角开始，根据 dp 值向左或上走，直到左上角
 */
class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n));
    dp[0][0] = grid[0][0];
    for (int i = 1; i < m; i++) dp[i][0] = dp[i - 1][0] + grid[i][0];
    for (int i = 1; i < n; i++) dp[0][i] = dp[0][i - 1] + grid[0][i];

    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
      }
    }

    return dp[m - 1][n - 1];
  }
};

/**
 * 状态压缩，一维dp
 */
class Solution1 {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    vector<int> dp(grid[0].size());
    dp[0] = grid[0][0];
    for (int i = 1; i < grid[0].size(); i++) {
      dp[i] = dp[i - 1] + grid[0][i];
    }

    for (int i = 1; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (j == 0)
          dp[j] = dp[j] + grid[i][0];
        else
          dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
      }
    }
    return dp[grid[0].size() - 1];
  }
};