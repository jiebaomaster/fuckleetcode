/**
 * https://leetcode-cn.com/problems/minimum-falling-path-sum/
 * https://labuladong.gitbook.io/algo/mu-lu-ye-2/mu-lu-ye/bei-wang-lu-deng-ji-chu
 * dp[i][j] 为下落到 [i,j] 位置的最小路径和
 * 本行的状态由上一行的三个位置中的最小值决定，要保证每个位置是有效的
 * dp[i][j] = matrix[i][j]+ min{matrix[i-1][j-1],
 *                              matrix[i-1][j],
 *                              matrix[i-1][j+1]}
 */
class Solution {
 public:
  int minFallingPathSum(vector<vector<int>>& matrix) {
    for (int i = 1; i < matrix.size(); i++) {
      vector<int>& dp = matrix[i];
      for (int j = 0; j < dp.size(); j++) {
        int p = j > 0 ? matrix[i - 1][j - 1] : 200; // 访问不能越界
        int c = matrix[i - 1][j];
        int n = j < dp.size() - 1 ? matrix[i - 1][j + 1] : 200; // 访问不能越界
        dp[j] = min(p, min(c, n)) + dp[j];
      }
    }
    // 此时最后一行是下落到最后一行每个位置的最小路径和，其最小值就是整个矩阵的下落最小路径和
    return *min_element(matrix[matrix.size() - 1].begin(),
                        matrix[matrix.size() - 1].end());
  }
};