/**
 * https://leetcode-cn.com/problems/unique-paths/
 * 设 dp[i][j] 表示走到 [i,j] 的路径条数
 * 则可以从上边 [i-1,j] 到达 [i,j]，也可以从左边 [i,j-1] 到达 [i,j]
 */
class Solution {
 public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n));
    // 最上边一层只能走一条路，即一直往右走
    for (int i = 0; i < m; i++) dp[i][0] = 1;
    // 最左边一层只能走一条路，即一直往下走
    for (int j = 0; j < n; j++) dp[0][j] = 1;

    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }
    return dp[m - 1][n - 1];
  }
};

/**
 * 从 [0,0] 到 [m,n] 一定会走 m+n-2 步，其中向下走 m-1 步，向右走 n-1 步
 * 只需要确定哪几步向下走就可以确定整条路径
 * 即组合数 C(m+n-2, n-1)
 */
