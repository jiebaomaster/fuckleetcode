/**
 * https://leetcode.cn/problems/maximal-rectangle/
 * https://leetcode.cn/problems/maximal-rectangle/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-1-8/
 * 
 * 按层解决问题。累加每一列的数，构成每一层的柱状图，就可以把问题转化为求柱状图中的最大矩形
 * 参考第 84 题
 * 对每一行都求出每个元素对应的高度，这个高度就是对应的连续1的长度，然后对每一行都更新一次最大矩形面积
 */
class Solution {
 public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> heights(m); // 每一行的柱状图
    int res = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (matrix[i][j] == '1') {
          heights[j]++; // 连续的 1
        } else {
          heights[j] = 0;
        }
      }
      // 求一行的最大矩形面积
      res = max(res, maximalRectangleInRow(heights));
    }

    return res;
  }

  int maximalRectangleInRow(vector<int>& heights) {
    heights.push_back(0);
    int n = heights.size();
    stack<int> s;
    int res = 0;
    for (int i = 0; i < n; i++) {
      while (!s.empty() && heights[s.top()] >= heights[i]) {
        int r = i;
        int h = heights[s.top()];
        s.pop();
        int l = -1;
        if (!s.empty()) l = s.top();
        res = max(res, h * (r - l - 1));
      }
      s.push(i);
    }
    return res;
  }
};