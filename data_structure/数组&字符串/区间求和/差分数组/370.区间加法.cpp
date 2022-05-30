/**
 * https://leetcode.cn/problems/range-addition/
 */
class Solution {
 public:
  vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
    vector<int> diff(length);
    for (auto& v : updates) {
      diff[v[0]] += v[2];
      if (v[1] + 1 < length) diff[v[1] + 1] -= v[2];
    }

    vector<int> res(length);
    res[0] = diff[0];
    for (int i = 1; i < length; i++) {
      res[i] = res[i - 1] + diff[i];
    }
    return res;
  }
};