/**
 * https://leetcode.cn/problems/max-points-on-a-line/
 * 方法一：暴力
 * 选择两个点 i[xi, yi], j[xj, yj] 构成一条直线，判断其他点是否在这条直线上
 * 若点 k[xk, yk] 在直线 ij 上，则直线 ik 和直线 kj 的斜率相等
 * 即 (yj - yk)/(xj - xk) == (yk - yi)/(xk - xi)
 * 由于除法产生的符点数精度可能丢失，可以转化成乘法判断
 * 即 (yj - yk) * (xk - xi) == (yk - yi) * (xj - xk)
 */
class Solution {
 public:
  int maxPoints(vector<vector<int>>& points) {
    int n = points.size();
    int res = 1;
    for (int i = 0; i < n; i++) {
      int xi = points[i][0];
      int yi = points[i][1];
      for (int j = i + 1; j < n; j++) {
        int cur = 2;
        int xj = points[j][0];
        int yj = points[j][1];
        for (int k = 0; k < n; k++) {
          if (k == i || k == j) continue;
          int xk = points[k][0];
          int yk = points[k][1];

          if ((yj - yk) * (xk - xi) == (yk - yi) * (xj - xk)) cur++;
        }
        res = max(res, cur);
      }
    }
    return res;
  }
};