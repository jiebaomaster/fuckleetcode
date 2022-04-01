/**
 * https://leetcode-cn.com/problems/walls-and-gates/
 * 多源 BFS
 * 计算从所有的门开始，到达各起点的距离
 */
class Solution {
 public:
  const int wall = 2147483647;
  void wallsAndGates(vector<vector<int>>& rooms) {
    vector<vector<bool>> used(rooms.size(),
                              vector<bool>(rooms[0].size(), false));
    queue<pair<int, int>> q;
    // 将所的门节点入队，作为起点
    for (int i = 0; i < rooms.size(); i++) {
      for (int j = 0; j < rooms[0].size(); j++) {
        if (rooms[i][j] == 0) {
          q.push({i, j});
        }
      }
    }

    int depth = 0;
    // 上下左右
    int mover[] = {-1, 1, 0, 0};
    int movec[] = {0, 0, -1, 1};
    while (!q.empty()) {  // 层序遍历
      depth++;
      for (int i = q.size(); i > 0; i--) {
        pair<int, int> node = q.front();
        q.pop();
        for (int j = 0; j < 4; j++) {  // 遍历上下左右四个方向的子节点
          pair<int, int> c = {node.first + mover[j], node.second + movec[j]};
          if (c.first >= 0 && c.first < rooms.size() &&       // 行标合法
              c.second >= 0 && c.second < rooms[0].size()) {  // 列标合法
            // 跳过障碍物和门
            if (rooms[c.first][c.second] == -1 || rooms[c.first][c.second] == 0)
              continue;
            else if (rooms[c.first][c.second] > depth) { // 碰到更短距离时更新
              rooms[c.first][c.second] = depth;
              q.push({c.first, c.second});
            }
          }
        }
      }
    }
  }
};