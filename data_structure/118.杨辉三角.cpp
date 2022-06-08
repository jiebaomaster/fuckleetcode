/**
 * https://leetcode.cn/problems/pascals-triangle/
 */
class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    if (numRows == 1) return {{1}};
    if (numRows == 2) return {{1}, {1, 1}};

    vector<vector<int>> res = {{1}, {1, 1}};
    for (int i = 2; i < numRows; i++) { // 遍历构建每一层
      vector<int> cur = {1};
      for (int j = 1; j < i; j++) { // 构建当前层
        cur.push_back(res[i - 1][j - 1] + res[i - 1][j]);
      }
      cur.push_back(1);
      res.push_back(cur);
    }
    return res;
  }
};