/**
 * @brief
 * 方法一：邻接矩阵+dfs
 */
class Solution {
 public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<bool> used(n);
    int cnt = 0;
    // 遍历每个节点，dfs标记所有的连通节点
    for (int i = 0; i < n; i++) {
      if (!used[i]) {
        cnt++;
        dfs(isConnected, used, i);
      }
    }
    return cnt;
  }
  void dfs(vector<vector<int>>& isConnected, vector<bool>& used, int i) {
    used[i] = true;

    for (int j = 0; j < used.size(); j++) {
      if (isConnected[i][j] == 1 && !used[j]) {
        dfs(isConnected, used, j);
      }
    }
  }
};

/**
 * 方法二：并查集
 */
class Solution {
 public:
  struct UnionFind {
    vector<int> father;

    UnionFind(int n) {
      father.resize(n);
      for (int i = 0; i < n; i++) {
        father[i] = i;
      }
    }

    int Find(int x) {
      int rx = x;
      while (father[x] != x) {
        x = father[x];
      }

      while (father[rx] != rx) {
        int n = father[rx];
        father[rx] = x;
        rx = n;
      }
      return x;
    }

    void Union(int a, int b) {
      int fa = Find(a);
      int fb = Find(b);
      if (fa != fb) father[fa] = fb;
    }

    int size() {
      int cnt = 0;
      for (int i = 0; i < father.size(); i++) {
        if (father[i] == i) {
          cnt++;
        }
      }
      return cnt;
    }
  };
  int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    UnionFind uf(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (isConnected[i][j] == 1) {
          uf.Union(i, j);
        }
      }
    }
    return uf.size();
  }
};