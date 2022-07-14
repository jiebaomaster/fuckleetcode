/**
 * https://leetcode.cn/problems/number-of-closed-islands/
 * 计算岛的数量，类似第 200 题
 * 区别在于对岛的边界有要求，只能以水为界，也就是不能以矩阵边界为界
 */
class Solution {
 public:
  int closedIsland(vector<vector<int>>& grid) {
    if (grid.size() == 0) return 0;
    int n = grid.size();
    int m = grid[0].size();
    int count = 0;
    // 尝试以每一个节点为起点
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 0) {
          if (dfs(grid, i, j)) count++;
        }
      }
    }
    return count;
  }

  int mx[4] = {0, 1, 0, -1};
  int my[4] = {1, 0, -1, 0};
  // 从 [i,j] 开始扩散，标记所有已访问的点，返回值表示是否是一个有效的岛
  bool dfs(vector<vector<int>>& grid, int i, int j) {
    // 超出边界，无效
    if (i < 0 || i >= grid.size() ||   // i 不越界
        j < 0 || j >= grid[0].size())  // j 不越界
      return false;
    // 碰到水边界，有效
    if (grid[i][j] == 2 || grid[i][j] == 1) return true;

    grid[i][j] = 2;
    // 向上下左右四个方向扩散
    bool f = true;
    for (int k = 0; k < 4; k++)
      if (!dfs(grid, i + mx[k], j + my[k])) f = false;

    return f;
  }
};
