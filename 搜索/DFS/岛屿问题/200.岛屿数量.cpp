/**
 * https://leetcode-cn.com/problems/number-of-islands/
 * 基础矩阵搜索
 */
class Solution {
 public:
  int numIslands(vector<vector<char>> &grid) {
    if (grid.size() == 0) return 0;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int count = 0;
    // 尝试以每一个节点为起点
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!visited[i][j] && grid[i][j] == '1') {
          dfs(grid, i, j, visited);
          count++;
        }
      }
    }
    return count;
  }
  int mx[4] = {0, 1, 0, -1};
  int my[4] = {1, 0, -1, 0};
  // 从 [i,j] 开始扩散，标记所有已访问的点
  void dfs(vector<vector<char>> &grid, int i, int j,
           vector<vector<bool>> &visited) {
    if (i < 0 || i >= grid.size() ||     // i 不越界
        j < 0 || j >= grid[0].size() ||  // j 不越界
        visited[i][j] ||                 // [i,j] 未被访问过
        grid[i][j] == '0')               // grid[i,j] 必须为 1
      return;

    visited[i][j] = true; // 标记已访问的点
    // 向上下左右四个方向扩散
    for(int k = 0; k < 4; k++)
      dfs(grid, i+mx[k], j + my[k], visited);
  }
};