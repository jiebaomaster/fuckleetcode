/**
 * https://leetcode-cn.com/problems/brick-wall/
 * 沿着矩阵的某一列画一条竖线，要求这条线穿过的砖块数量最小，求这条线穿过的砖块数量
 * 穿过的砖块数量 = 砖块的高（矩阵行数）- 线经过的边沿数
 * 问题转化为求哪个边沿出现的次数最多
 */
class Solution {
 public:
  int leastBricks(vector<vector<int>>& wall) {
    unordered_map<int, int> edge; // 边沿出现的次数
    int ret = 0;
    for (int i = 0; i < wall.size(); i++) {
      int cur = 0; // 当前行的边沿
      for (int j = 0; j < wall[i].size() - 1; j++) {
        cur += wall[i][j];
        edge[cur]++;
        ret = max(ret, edge[cur]);
      }
    }
    return wall.size() - ret;
  }
};