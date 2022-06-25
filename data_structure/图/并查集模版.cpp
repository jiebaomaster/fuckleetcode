struct UnionFind {
  vector<int> father; // i 的父亲编号为 father[i]

  UnionFind(int size) {
    father.resize(size);
    for (int i = 0; i < size; i++) father[i] = i;
  }

  // 合并集合
  void Union(int a, int b) {
    int fathera = Find(a);
    int fatherb = Find(b);
    if (fathera != fatherb) father[fathera] = fatherb;
  }

  // 查找根
  int Find(int x) {
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

  // 返回根节点个数
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