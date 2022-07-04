/**
 * https://leetcode.cn/problems/triangle/
 * 方法一：自顶向下
 */
class Solution {
 public:
  int minimumTotal(vector<vector<int>>& triangle) {
    vector<int> dp(triangle.back().size(), 100000);
    dp[0] = triangle[0][0];
    for (int i = 1; i < triangle.size(); i++) {
      for (int j = i; j >= 0; j--) {
        if (j == 0)
          dp[j] = dp[j] + triangle[i][j];
        else
          dp[j] = min(dp[j], dp[j - 1]) + triangle[i][j];
      }
    }
    int res = INT_MAX;
    for (auto n : dp) {
      res = min(res, n);
    }
    return res;
  }
};

/**
 * 方法二：自底向上，原地修改
 */
class Solution {
 public:
  int minimumTotal(vector<vector<int>>& triangle) {
    for (int i = triangle.size() - 2; i >= 0; i--) {
      for (int j = 0; j < triangle[i].size(); j++) {
        triangle[i][j] =
            min(triangle[i + 1][j], triangle[i + 1][j + 1]) + triangle[i][j];
      }
    }
    return triangle[0][0];
  }
};