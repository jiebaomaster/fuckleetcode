/**
 * https://leetcode-cn.com/problems/simplify-path/
 */
class Solution {
 public:
  string simplifyPath(string path) {
    int n = path.size();
    vector<string> st; // 维护每一级路径的栈
    int l = 1, r = 1; // [l,r)
    while (r < n) {
      if (path[r] == '/') { // 跳过所有 /
        while (r < n && path[r] == '/') r++;
      } else if (path[r] == '.') {
        int cnt = 0;
        while (r < n && path[r] != '/') {
          cnt++;
          r++;
        }
        if (cnt == 1) { // 一个点
        } else if (cnt == 2) { // 两个点，从栈中弹出一级路径
          if (!st.empty()) st.pop_back();
        } else { // 多个点，认为是有效的一级路径
          st.push_back(path.substr(l, r - l));
        }
      } else { // 字符
        while (r < n && path[r] != '/') r++;
        // [l,r)
        st.push_back(path.substr(l, r - l));
      }
      l = r;
    }
    if (st.empty()) return "/";
    // 用 / 拼接返回路径
    string res;
    for (auto& s : st) {
      res += "/" + s;
    }
    return res;
  }
};