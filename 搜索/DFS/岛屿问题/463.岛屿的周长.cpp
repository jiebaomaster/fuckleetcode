/**
 * https://leetcode.cn/problems/island-perimeter/
 * 方法一：dfs
 */
class Solution {
 public:
  int islandPerimeter(vector<vector<int>>& grid) {
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == 1) {
          return dfs(grid, i, j);
        }
      }
    }
    return 0;
  }

  int mx[4] = {0, 1, 0, -1};
  int my[4] = {1, 0, -1, 0};
  int dfs(vector<vector<int>>& grid, int i, int j) {
    grid[i][j] = 2; // 标记，防止走回头路
    int res = 0;
    for (int k = 0; k < 4; k++) {
      int x = i + mx[k];
      int y = j + my[k];
      // 碰到边界，记一个边长
      if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() ||
          grid[x][y] == 0) {
        res++;
      } else if (grid[x][y] == 1) { // 递归计算相邻岛
        res += dfs(grid, x, y);
      }
    }
    return res;
  }
};