/**
 * https://leetcode-cn.com/problems/max-area-of-island/
 */
class Solution {
 public:
  int maxArea;

  int dfs(vector<vector<int>>& grid, int i, int j) {
    if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() &&
        grid[i][j] == 1) {
      grid[i][j] = 0; // 防止重复计算
      // 岛屿面积 = 当前陆地 + 四周陆地
      int area = 1 + dfs(grid, i - 1, j) + dfs(grid, i + 1, j) +
                 dfs(grid, i, j - 1) + dfs(grid, i, j + 1);
      maxArea = max(maxArea, area);
      return area;
    }
    return 0;
  }
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    maxArea = 0;
    // 尝试以每一个节点为起点
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == 1) {
          dfs(grid, i, j);
        }
      }
    }
    return maxArea;
  }
};