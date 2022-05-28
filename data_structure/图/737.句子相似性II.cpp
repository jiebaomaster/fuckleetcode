/**
 * https://leetcode.cn/problems/sentence-similarity-ii/
 * 节点为 string 的并查集
 */
class Solution {
 public:
  struct UnionFind {
    unordered_map<string, string> father;
    UnionFind() {}
    string Find(string x) {
      if (father.find(x) == father.end()) {
        father[x] = x;
      }
      auto rx = x;
      while (father[x] != x) {
        x = father[x];
      }

      while (father[rx] != rx) {
        auto n = father[rx];
        father[rx] = x;
        rx = n;
      }
      return x;
    }
    void Union(string& a, string& b) {
      auto fa = Find(a);
      auto fb = Find(b);
      if (fa != fb) father[fa] = fb;
    }

    bool same(string a, string b) { return Find(a) == Find(b); }
  };

  bool areSentencesSimilarTwo(vector<string>& sentence1,
                              vector<string>& sentence2,
                              vector<vector<string>>& similarPairs) {
    if (sentence1.size() != sentence2.size()) return false;
    UnionFind uf; // 维护相似性的并查集，相似的节点在一个集合中
    for (auto edge : similarPairs) {
      uf.Union(edge[0], edge[1]);
    }
    int n = sentence1.size();
    for (int i = 0; i < n; i++) {
      if (sentence1[i] == sentence2[i])
        continue;
      else if (!uf.same(sentence1[i], sentence2[i])) // 判断相似性
        return false;
    }
    return true;
  }
};