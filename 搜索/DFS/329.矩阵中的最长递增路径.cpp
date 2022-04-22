/**
 * https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix
 * dfs+记忆化搜索
 * 每个节点的递增路径长度是不变的，且计算的时候会依赖其他结点的路径长度，
 * 所以可以将已经计算出的结果缓存起来
 */
class Solution {
 public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    // 缓存已经计算出的路径长度
    vector<vector<int>> len(n, vector<int>(m));
    int res = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        res = max(res, dfs(matrix, len, i, j));
      }
    }
    return res;
  }

  int move[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  int dfs(vector<vector<int>>& matrix, vector<vector<int>>& len, int i, int j) {
    int n = matrix.size();
    int m = matrix[0].size();

    if (len[i][j] != 0) return len[i][j];
    int res = 1; // 结点的最短路径长度为本身 1
    for (int k = 0; k < 4; k++) {
      int ii = i + move[k][0];
      int jj = j + move[k][1];
      if (ii >= 0 && ii < n && jj >= 0 && jj < m) { // 不越界
        if (matrix[i][j] < matrix[ii][jj]) // 递增
          res = max(res, dfs(matrix, len, ii, jj) + 1);
      }
    }
    len[i][j] = res;
    return res;
  }
};