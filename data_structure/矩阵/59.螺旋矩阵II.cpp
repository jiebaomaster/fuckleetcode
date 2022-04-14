class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n));
    // 左上角
    int sx = 0, sy = 0;
    // 右下角
    int ex = n - 1, ey = n - 1;
    int cnt = 1;
    while (sx < ex) {
      // up
      for (int i = sy; i < ey; i++) res[sx][i] = cnt++;
      // right
      for (int i = sx; i < ex; i++) res[i][ey] = cnt++;
      // down
      for (int i = ey; i > sy; i--) res[ex][i] = cnt++;
      // left
      for (int i = ex; i > sx; i--) res[i][sy] = cnt++;
      // update
      sx++;
      sy++;
      ex--;
      ey--;
    }
    if (n % 2) res[sx][sy] = cnt;
    return res;
  }
};