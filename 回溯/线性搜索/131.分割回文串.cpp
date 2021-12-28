/**
 * https://leetcode-cn.com/problems/palindrome-partitioning/
 * 一个长度为 len 的字符串中可分割的点有 len-1 个，分割时可选取其中的任意个分割点
 * 1. 先用 dfs 求出所有分割方案
 * 2. 对于每一种分割方案计算是否每一个子串都是回文
 */
class Solution {
 public:
  vector<vector<string>> res;
  vector<vector<string>> partition(string s) {
    vector<int> track;
    dfs(s, track, 1);
    return res;
  }
  // 求出所有分割方案
  void dfs(string &s, vector<int> &track, int index) {
    if (index == s.size()) { // 分割点只有 len-1 个
      getres(s, track);
      return;
    }
    // 该点要分割
    track.push_back(index);
    dfs(s, track, index + 1);
    track.pop_back();
    // 该点不分割
    dfs(s, track, index + 1);
  }
  // 处理当前分割方案
  void getres(string &s, vector<int> &track) {
    int l = 0;
    int r = 0;
    vector<string> tmp; // 存储回文子串
    // 有 n 个分割点[k_1,k_2...k_n]，则要判断 n+1 个子串：
    // [0,k_1-1],[k_1,k_2-1]...[k_n,len-1] 是否为回文
    for (int i = 0; i <= track.size(); i++) {
      l = i - 1 >= 0 ? track[i - 1] : 0;
      r = i == track.size() ? s.size() : track[i];
      r--;
      if (ishuiwen(l, r, s)) {
        tmp.push_back(s.substr(l, r - l + 1));
      } else {
        return;
      }
    }
    res.push_back(tmp);
  }
  // 判断 s[l,r] 是否为回文
  // 这里也可以先使用 DP 预先求出 s[i,j] 是否为回文，判断时只需 O(1)
  bool ishuiwen(int l, int r, string &s) {
    while (l <= r) {
      if (s[l] != s[r]) return false;
      l++;
      r--;
    }
    return true;
  }
};