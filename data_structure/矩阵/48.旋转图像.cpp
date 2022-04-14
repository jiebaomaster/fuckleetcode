/**
 * https://leetcode-cn.com/problems/rotate-image/
 * 将矩阵顺时针旋转 90 度
 */
class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    doRotate(matrix, {0, 0}, {matrix.size() - 1, matrix[0].size() - 1});
  }
  void doRotate(vector<vector<int>>& matrix, pair<int, int> start,
                pair<int, int> end) {
    int n = end.first - start.first;
    if (n <= 0) return;

    // 旋转最外圈的元素
    // top -> right, right -> bottom, bottom -> left, left -> top
    auto top = start;
    auto bottom = end;
    pair<int, int> left = {end.first, start.first};
    pair<int, int> right = {start.first, end.second};
    for (int i = 0; i < n; i++) {
      int tmp = matrix[top.first][top.second];
      matrix[top.first][top.second] = matrix[left.first][left.second];
      matrix[left.first][left.second] = matrix[bottom.first][bottom.second];
      matrix[bottom.first][bottom.second] = matrix[right.first][right.second];
      matrix[right.first][right.second] = tmp;

      top.second++;
      bottom.second--;
      left.first--;
      right.first++;
    }

    // 旋转下一层
    doRotate(matrix, {start.first + 1, start.second + 1},
             {end.first - 1, end.second - 1});
  }
};

/**
 * 迭代写法
 */
class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    pair<int, int> start = {0, 0};
    pair<int, int> end = {n - 1, n - 1};
    for (int k = 0; k < n / 2; k++) {
      // this level
      auto top = start;
      auto bottom = end;
      pair<int, int> left = {end.first, start.first};
      pair<int, int> right = {start.first, end.second};
      for (int i = start.first; i < end.first; i++) {
        int tmp = matrix[top.first][top.second];
        matrix[top.first][top.second] = matrix[left.first][left.second];
        matrix[left.first][left.second] = matrix[bottom.first][bottom.second];
        matrix[bottom.first][bottom.second] = matrix[right.first][right.second];
        matrix[right.first][right.second] = tmp;

        top.second++;
        bottom.second--;
        left.first--;
        right.first++;
      }
      start = {start.first + 1, start.second + 1};
      end = {end.first - 1, end.second - 1};
    }
  }
};