/**
 * https://leetcode.cn/problems/max-submatrix-lcci/
 * https://leetcode.cn/problems/max-submatrix-lcci/solution/zhe-yao-cong-zui-da-zi-xu-he-shuo-qi-you-jian-dao-/
 * 第 53 题求一维数组中的最大子数组和，本题求矩阵中的最大子矩阵和
 * 通过求子矩阵中每一列的和，将二维最大转换为一维最大
 */
class Solution {
 public:
  vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    //记录当前i~j行组成大矩阵的每一列的和，将二维转化为一维
    vector<int> sums(m);
    int cur = INT_MIN;
    vector<int> res;
    for (int i = 0; i < n; i++) {  //以i为上边，从上而下扫描
      // 每次更换子矩形上边，就要清空 sums，重新计算每列的和
      for (int k = 0; k < m; k++) sums[k] = 0;
      // 子矩阵的下边，从i到N-1，不断增加子矩阵的高
      for (int j = i; j < n; j++) {  
        // 在 i～j 行组成的子矩阵中求最大矩阵和
        int dp = -1;  // 到 k 位置的最大连续子数组和
        pair<int, int> begin;
        for (int k = 0; k < m; k++) {
          sums[k] += matrix[j][k];

          if (dp < 0) {  // 从新的矩阵起点开始
            dp = sums[k];
            begin = {i, k};
          } else {
            dp += sums[k];
          }

          if (dp > cur) {  // 更新最大值
            cur = dp;
            res = {begin.first, begin.second, j, k};
          }
        }
      }
    }
    return res;
  }
};