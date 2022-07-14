/**
 * https://leetcode.cn/problems/making-a-large-island/
 * https://leetcode.cn/problems/making-a-large-island/solution/zui-da-ren-gong-dao-by-leetcode/
 * 允许一个 0 变为 1，则应该由 0 出发考虑
 * 首先跑一次dfs找到所有的联通块，统计每个点所属的联通块标号以及该联通块下点的个数。
 * 之后枚举所有为0的点，拓展四周为1的点，进行合并判断。
 * 注意相邻点属于同一个岛时不能重复累加
 */
class Solution {
 public:
  int largestIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    // 1. 统计所有岛的面积
    unordered_map<int, int> area; // 存储每个岛的面积，避免重复计算
    // 将同一岛屿的值改为 cnt，相当于并查集的根
    int cnt = 2; // 从 2 开始，防止与 1 冲突导致 dfs 栈溢出
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 1) {
          
          area[cnt] = dfs(grid, i, j, cnt);
          cnt++;
        }
      }
    }
    int res = 0;
    // 2. 遍历每个 0，尝试变为 1，累加相邻岛的面积
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 0) {
          // 去重，相邻位置属于同一个岛时避免重复累加
          unordered_set<int> neighbors = {0};
          int cur = 1; // 将当前的 0 变为 1
          // 累加相邻岛的面积
          for (int k = 0; k < 4; k++) {
            int x = i + mx[k];
            int y = j + my[k];
            if (x >= 0 && x < n && y >= 0 && y < m &&
                !neighbors.count(grid[x][y])) {
              cur += area[grid[x][y]];
              neighbors.insert(grid[x][y]);
            }
          }
          res = max(res, cur);
        }
      }
    }
    // 岛中没有 0，最大面积应该是整个矩阵
    if (res == 0) res = n * m;
    return res;
  }

  int mx[4] = {0, 1, 0, -1};
  int my[4] = {1, 0, -1, 0};
  // 计算岛的面积
  int dfs(vector<vector<int>>& grid, int i, int j, int k) {
    if (i < 0 || i >= grid.size() 
        || j < 0 || j >= grid[0].size() 
        || grid[i][j] != 1) // 注意这里的判断条件应该是不等于 1，因为计算时会修改岛的值
      return 0;

    grid[i][j] = k;
    int res = 1;
    for (int n = 0; n < 4; n++) res += dfs(grid, i + mx[n], j + my[n], k);
    return res;
  }
};