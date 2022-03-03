/**
 * https://leetcode-cn.com/problems/spiral-matrix/
 * 
 */
class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res; // 结果集
    pair<int, int> begin = {0, 0}; // 左上角
    pair<int, int> end = {matrix.size() - 1, matrix[0].size() - 1}; // 右下角
    /**
     * 顺时针遍历，每次遍历最外围的一圈，遍历的范围由左上角和右下角元素界定
     * 1 1 1 1 1 
     * 4       2
     * 4       2
     * 4 3 3 3 2
     */
    while (begin.first <= end.first && begin.second <= end.second) {
      // 完整遍历最上边
      for (int i = begin.second; i <= end.second; i++) {
        res.push_back(matrix[begin.first][i]);
      }
      // 遍历最右边，跳过第一个元素，因为已经在最上边遍历过了
      for (int i = begin.first + 1; i <= end.first; i++) {
        res.push_back(matrix[i][end.second]);
      }
      // 遍历最下边，跳过右下角和左下角
      if (begin.first < end.first) { // 只有一行元素时不用遍历最下边
        for (int i = end.second - 1; i > begin.second; i--) {
          res.push_back(matrix[end.first][i]);
        }
      }
      // 遍历最左边，跳过左上角
      if (begin.second < end.second) { // 只有一列元素时不用遍历最左边
        for (int i = end.first; i > begin.first; i--) {
          res.push_back(matrix[i][begin.second]);
        }
      }
      begin.first++;
      begin.second++;
      end.first--;
      end.second--;
    }
    return res;
  }
};