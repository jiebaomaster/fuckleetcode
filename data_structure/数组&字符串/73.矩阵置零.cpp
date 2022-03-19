/**
 * https://leetcode-cn.com/problems/set-matrix-zeroes/
 * 方法一：标记数组
 * 用两个标记数组分别记录每一行和每一列是否有零出现，
 * 先遍历一边填充标记数组，再遍历标记数组回填 0
 * 空间复杂度为 O(n+m)
 */
class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> row(n);
    vector<int> col(m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (matrix[i][j] == 0) {
          row[i] = 1;
          col[j] = 1;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (row[i] == 1) {
        for (int j = 0; j < m; j++) matrix[i][j] = 0;
      }
    }
    for (int j = 0; j < m; j++) {
      if (col[j] == 1) {
        for (int i = 0; i < n; i++) matrix[i][j] = 0;
      }
    }
  }
};

/**
 * 方法二：标记变量
 * 可以用矩阵的第一行和第一列代替方法一中的两个标记数组，但这样会导致
 * 原数组的第一行和第一列被修改，无法记录它们是否原本包含 0。因此我们
 * 需要额外使用两个标记变量分别记录第一行和第一列是否原本包含 0。
 * 空间复杂度为 O(1)
 */
class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    // 标记变量分别记录第一行和第一列是否原本包含 0
    int c0 = 0, r0 = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (matrix[i][j] == 0) {
          if (i == 0) r0 = 1;
          if (j == 0) c0 = 1;
          matrix[i][0] = 0;
          matrix[0][j] = 0;
        }
      }
    }
    // 回填行
    for (int i = 1; i < n; i++) {
      if (matrix[i][0] == 0) {
        for (int j = 0; j < m; j++) matrix[i][j] = 0;
      }
    }
    // 回填列
    for (int j = 1; j < m; j++) {
      if (matrix[0][j] == 0) {
        for (int i = 0; i < n; i++) matrix[i][j] = 0;
      }
    }
    // 回填第一行
    if (r0) {
      for (int j = 0; j < m; j++) matrix[0][j] = 0;
    }
    // 回填第一列
    if (c0) {
      for (int i = 0; i < n; i++) matrix[i][0] = 0;
    }
  }
};