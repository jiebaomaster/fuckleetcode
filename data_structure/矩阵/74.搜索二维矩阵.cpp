/**
 * https://leetcode-cn.com/problems/search-a-2d-matrix/
 * 将矩阵按行展开，就是一个递增数组，可以用二分查找
 * 关键在于将一维的位置转换为二维
 */
class Solution {
 public:
  pair<int, int> kPostion(vector<vector<int>>& matrix, int k) {
    int i = k / matrix[0].size();
    int j = k % matrix[0].size();
    return {i, j};
  }
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int l = 0, r = matrix.size() * matrix[0].size();
    while (l < r) {
      int mid = l + (r - l) / 2;
      auto p = kPostion(matrix, mid);
      if (matrix[p.first][p.second] < target)
        l = mid + 1;
      else
        r = mid;
    }
    if (r == matrix.size() * matrix[0].size()) return false;
    auto res = kPostion(matrix, r);
    return matrix[res.first][res.second] == target;
  }
};