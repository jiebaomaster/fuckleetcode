/**
 * https://leetcode-cn.com/problems/maximal-square/
 * https://leetcode-cn.com/problems/maximal-square/solution/li-jie-san-zhe-qu-zui-xiao-1-by-lzhlyle/
 * 
 * 设 dp[i,j] 为 以 matrix[i,j] 为 右下角 的 1 正方形的最大边长,
 * 计算出所有 dp(i,j) 的值，那么其中的最大值即为矩阵中只包含 1 的正方形的边长最大值，
 * 其平方即为最大正方形的面积。
 * 对于每个位置 (i,j)，检查在矩阵中该位置的值：
 * 1. 如果该位置的值是 0，则 dp[i,j]=0，因为当前位置不可能在由 1 组成的正方形中
 * 2. 如果该位置的值是 1，则 dp[i,j] 的值由其上方、左方和左上方的三个相邻位置的 dp 值决定
 *    dp[i,j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
 */
class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    vector<vector<int>> dp(matrix.size() + 1,
                           vector<int>(matrix[0].size() + 1));

    int ret = 0;
    for (int i = 1; i <= matrix.size(); i++) {
      for (int j = 1; j <= matrix[0].size(); j++) {
        if (matrix[i - 1][j - 1] == '1') {
          int tmp = min(dp[i - 1][j], dp[i][j - 1]);
          dp[i][j] = min(tmp, dp[i - 1][j - 1]) + 1;
          ret = max(ret, dp[i][j]);
        }
      }
    }
    return ret * ret;
  }
};