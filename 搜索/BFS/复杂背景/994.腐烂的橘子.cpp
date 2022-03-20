/**
 * https://leetcode-cn.com/problems/rotting-oranges/
 * 在矩阵中向上下左右四个方向扩展的 bfs
 */
class Solution {
 public:
  int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int depth = 0;
    queue<pair<int, int>> q;
    int cnt_flash = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 2) {
          q.push({i, j}); // 将所有腐烂的橘子入队，多开端 bfs
        } else if (grid[i][j] == 1) {
          cnt_flash++; // 统计新鲜的橘子个数
        }
      }
    }
    // 上下左右
    int mover[] = {-1, 1, 0, 0};
    int movec[] = {0, 0, -1, 1};
    while (!q.empty() && cnt_flash > 0) {
      depth++; // bfs 一轮即时间过去一次
      for (int i = q.size(); i > 0; i--) {
        auto node = q.front();
        q.pop();
        for (int j = 0; j < 4; j++) { // 遍历上下左右四个方向的子节点
          pair<int, int> c = {node.first + mover[j], node.second + movec[j]};

          if (c.first >= 0 && c.first < n && // 行标合法
            c.second >= 0 && c.second < m && // 列标合法
              grid[c.first][c.second] == 1) { // 是个新鲜的橘子
            grid[c.first][c.second] = 2; // 新鲜的橘子在这一轮腐烂
            q.push(c); // 入队，下一轮从该橘子开始
            cnt_flash--; // 更新新鲜的橘子数
          }
        }
      }
    }

    return cnt_flash ? -1 : depth;
  }
};