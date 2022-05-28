/**
 * https://leetcode.cn/problems/number-of-connected-components-in-an-undirected-graph/
 *
 * 方法一：构建临接表+dfs
 */
class Solution {
 public:
  int countComponents(int n, vector<vector<int>>& edges) {
    vector<list<int>> g(n, list<int>());  // 临接表
    // 构建临接表，这里是无向图，一次要添加两条边
    for (auto& edge : edges) {
      g[edge[0]].push_back(edge[1]);
      g[edge[1]].push_back(edge[0]);
    }
    vector<bool> used(n);  // 节点是否使用
    int cnt = 0;
    // 遍历每个节点，dfs标记所有的连通节点
    for (int i = 0; i < n; i++) {
      if (!used[i]) {
        cnt++;
        dfs(g, used, i);
      }
    }
    return cnt;
  }
  void dfs(vector<list<int>>& g, vector<bool>& used, int i) {
    used[i] = true;
    for (auto n : g[i]) {
      if (!used[n]) dfs(g, used, n);
    }
  }
};

/**
 * 方法二：并查集
 */
class Solution {
 public:
  struct UnionFind {
    vector<int> father; // 指向父节点的数组
    UnionFind(int n) {
      father.resize(n);
      // -1 表示本身是根节点
      fill(father.begin(), father.end(), -1);
    }
    // 合并 a 和 b 所在的集合
    void Union(int a, int b) {
      int fa = Find(a);
      int fb = Find(b);
      if (fa != fb) father[fa] = fb;
    }
    // 查找 x 所在集合的根节点
    int Find(int x) {
      int rx = x;
      while (father[x] != -1) {
        x = father[x];
      }
      // 路径压缩
      if (father[x] != -1)
        while (father[rx] != x) {
          int n = father[rx];
          father[rx] = x;
          rx = n;
        }
      return x;
    }
    // 获取当前图中集合的个数
    int size() {
      int cnt = 0;
      for (int f : father) {
        if (f == -1) cnt++;
      }
      return cnt;
    }
  };
  int countComponents(int n, vector<vector<int>>& edges) {
    UnionFind uf(n);
    for (auto& edge : edges) {
      // 合并相邻边所在集合
      uf.Union(edge[0], edge[1]);
    }
    return uf.size();
  }
};