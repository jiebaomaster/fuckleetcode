/**
 * https://leetcode.cn/problems/path-with-minimum-effort/
 *
 * 方法一：并查集
 */
class Solution {
  struct UnionFind {
    vector<int> father;
    UnionFind(int size) {
      father.resize(size);
      for (int i = 0; i < size; i++) father[i] = i;
    }
    void Union(int a, int b) {
      int fathera = find(a);
      int fatherb = find(b);
      if (fathera != fatherb) father[fathera] = fatherb;
    }

    int find(int x) {
      int rx = x;
      while (father[x] != x) {
        x = father[x];
      }
      while (father[rx] != x) {
        int next = father[rx];
        father[rx] = x;
        rx = next;
      }

      return x;
    }
  };

 public:
  int minimumEffortPath(vector<vector<int>>& heights) {
    int n = heights.size();
    int m = heights[0].size();
    vector<vector<int>> edges;  // 从点 a 到点 b 的边权重为 p {a, b, p}
    // 构建所有边
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int id = i * m + j;
        if (i > 0) {
          edges.push_back({id - m, id, abs(heights[i][j] - heights[i - 1][j])});
        }
        if (j > 0) {
          edges.push_back({id - 1, id, abs(heights[i][j] - heights[i][j - 1])});
        }
      }
    }
    // 将边从小到大排序
    sort(edges.begin(), edges.end(),
         [](const auto& lhs, const auto& rhs) { return lhs[2] < rhs[2]; });
    UnionFind uf(n * m);
    int res = 0;
    // 从小到大选中边，直到 左上角 和 右下角 连通，此时边长度就是所求路径消耗
    // 因为跳出循环前所遍历的最后一条边必然是最优路径上的边，而且是 权值 最大的边
    for (auto& e : edges) {
      uf.Union(e[0], e[1]);
      res = max(res, e[2]);
      if (uf.find(0) == uf.find(n * m - 1)) {
        break;
      }
    }
    return res;
  }
};

/**
 * 方法二：单源最短路径
 * 可以使用任一单源最短路径的算法（例如 Dijkstra 算法），
 * 只需要在维护当前路径长度时，将其修改为题目中的定义即可。
 */
class Solution {
 public:
  int minimumEffortPath(vector<vector<int>>& heights) {
    int n = heights.size();
    int m = heights[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m));

    int mx[] = {0, 1, 0, -1};
    int my[] = {1, 0, -1, 0};
    // 优先级队列，加速寻找距离起点最近的节点
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        heap;  // <w, i*m+j>
    heap.push({0, 0});
    int res = 0;
    while (!heap.empty()) {
      auto closest = heap.top();
      heap.pop();
      int x = closest.second / m;
      int y = closest.second % m;
      
      // 跳过重复节点
      if (visited[x][y]) continue;
      // 找到了目标点
      if (x == n - 1 && y == m - 1) return closest.first;

      // 标记访问
      visited[x][y] = true;

      // 遍历 (x,y) 相邻节点，更新相邻节点距离原点的距离
      for (int i = 0; i < 4; i++) {
        int nx = mx[i] + x;
        int ny = my[i] + y;

        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        heap.push({max(closest.first, abs(heights[x][y] - heights[nx][ny])),
                   nx * m + ny});
      }
    }
    return 0;
  }
};