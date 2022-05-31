/**
 * https://leetcode.cn/problems/range-sum-query-2d-immutable/
 * https://leetcode.cn/problems/range-sum-query-2d-immutable/solution/er-wei-qu-yu-he-jian-suo-ju-zhen-bu-ke-b-2z5n/
 * 二维前缀和，矩阵中的递推关系
 */
class NumMatrix {
  vector<vector<int>> prefix;

 public:
  NumMatrix(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    prefix.resize(n + 1);
    prefix[0].resize(m + 1);
    for (int i = 1; i <= n; i++) {
      prefix[i].resize(m + 1);
      for (int j = 1; j <= m; j++) {
        prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] -
                       prefix[i - 1][j - 1] + matrix[i - 1][j - 1];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    return prefix[row2 + 1][col2 + 1] - prefix[row1][col2 + 1] -
           prefix[row2 + 1][col1] + prefix[row1][col1];
  }
};
