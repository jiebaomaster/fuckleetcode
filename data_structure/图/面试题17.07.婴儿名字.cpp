/**
 * https://leetcode.cn/problems/baby-names-lcci/
 */
class Solution {
  unordered_map<string, string> father;
  string Find(string &x) {
    if (!father.count(x)) {
      father[x] = x;
    }
    // 路径压缩时用字典序最小的字符串作为根
    string root = x;
    string xx = x;
    while (father[x] != x) {
      x = father[x];
      if (root < x) root = x;
    }

    while (father[xx] != xx) {
      auto f = father[xx];
      father[xx] = root;
      xx = f;
    }
    father[xx] = root;
    return root;
  }
  void Union(string &a, string &b) {
    auto fa = Find(a);
    auto fb = Find(b);
    if (fa != fb) father[fa] = fb;
    // 重新执行查询，确保用字典序最小的字符串作为根
    Find(a);
    Find(b);
  }

 public:
  vector<string> trulyMostPopular(vector<string> &names,
                                  vector<string> &synonyms) {
    // 记录相等关系
    for (auto &s : synonyms) {
      auto dot = s.find(',');
      auto a = s.substr(1, dot - 1);
      auto b = s.substr(dot + 1, s.size() - dot - 2);
      Union(a, b);
    }
    // 统计名字的个数
    unordered_map<string, int> times;
    for (auto &n : names) {
      auto l = n.find('(');
      auto name = n.substr(0, l);
      auto t = n.substr(l + 1, n.size() - l - 2);
      times[father[name]] += atoi(t.c_str());
    }
    // 输出根的名字个数
    vector<string> res;
    for (auto kv : father) {
      if (kv.second == kv.first) {
        res.push_back(kv.first + "(" + to_string(times[kv.first]) + ")");
      }
    }
    return res;
  }
};