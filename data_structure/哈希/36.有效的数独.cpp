/**
 * https://leetcode.cn/problems/valid-sudoku/
 * 三个条件：
 * 数字 1-9 在每一行只能出现一次。
 * 数字 1-9 在每一列只能出现一次。
 * 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次
 *
 * 方法一：简单判断 O(n^3)
 */
class Solution {
 public:
  bool isValidSudoku(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] == '.') continue;
        // row
        for (int k = 0; k < 9; k++) {
          if (k != j && board[i][j] == board[i][k]) {
            return false;
          }
        }
        // col
        for (int k = 0; k < 9; k++) {
          if (k != i && board[i][j] == board[k][j]) {
            return false;
          }
        }

        // block
        int r = 3 * (i / 3);
        int c = 3 * (j / 3);
        for (int ii = r; ii < r + 3; ii++) {
          for (int jj = c; jj < c + 3; jj++) {
            if (i != ii && j != jj && board[i][j] == board[ii][jj])
              return false;
          }
        }
      }
    }
    return true;
  }
};

/**
 * 方法二：位置哈希 O(n^2)
 */
class Solution1 {
 public:
  bool isValidSudoku(vector<vector<char>>& board) {
    /* 哈希表判断当前某位数字是否合法 */
    // 记录某行，某位数字是否已经被摆放
    vector<vector<bool>> row(9, vector<bool>(9));
    // 记录某列，某位数字是否已经被摆放
    vector<vector<bool>> col(9, vector<bool>(9));
    // 记录某 3x3 宫格内，某位数字是否已经被摆放
    vector<vector<bool>> block(9, vector<bool>(9));

    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] == '.') continue;
        int r = i;
        int c = j;
        int b = i / 3 * 3 + j / 3;  // 将3*3的区块映射到行
        int num = board[i][j] - '1';
        // 已经存在，返回 false
        if (row[r][num] || col[c][num] || block[b][num]) return false;
        // 更新存在
        row[r][num] = true;
        col[c][num] = true;
        block[b][num] = true;
      }
    }
    return true;
  }
};