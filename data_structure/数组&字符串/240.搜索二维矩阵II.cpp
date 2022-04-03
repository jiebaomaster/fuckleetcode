/**
 * https://leetcode-cn.com/problems/search-a-2d-matrix-ii/
 * 在一个行升序，列升序的二维数组中查找一个数
 * 从右向左看
 * 在一个以 matrix[n-1][0] 为左下角，以 matrix[i][j] 为右上角的矩阵中搜索，
 * 从 matrix 的右上角开始：
 * 若 matrix[i][j] > target 则第 j 列全都大于 target，向左走
 * 若 matrix[i][j] < target 则第 i 行全都小于 target，向下走
 */
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int i = 0, j = matrix[0].size() - 1;
    while (i < matrix.size() && j >= 0) {
      if (matrix[i][j] == target)
        return true;
      else if (matrix[i][j] < target)
        i++;
      else
        j--;
    }
    return false;
  }
};