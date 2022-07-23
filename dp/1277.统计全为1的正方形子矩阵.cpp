/**
 * https://leetcode.cn/problems/count-square-submatrices-with-all-ones/
 * 类似第 221 题，以 [i,j] 为右下角的最大正方形为 dp[i][j]，则以 [i,j] 为右下角的正方形个数为 dp[i][j]，累加每一个
 */
class Solution {
 public:
  int countSquares(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    int res = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (matrix[i - 1][j - 1] == 1) {
          dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
          res += dp[i][j];
        }
      }
    }
    return res;
  }
};