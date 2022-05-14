/**
 * https://leetcode-cn.com/problems/sudoku-solver/
 * https://labuladong.gitee.io/algo/4/29/108/
 * 解数独问题，判断矩阵中每一个位置的取值是否满足条件，逐行遍历，dfs 只有向右一个方向，需要注意换行
 */
class Solution {
 public:
  void solveSudoku(vector<vector<char>> &board) { 
    backtrack(board, 0, 0); // 从 [0,0] 开始遍历
  }

  // 逐行遍历矩阵中的每一个位置，回溯求解每一个未知位置
  // [i,j] 的下一个位置是 [i,j+1]，如果到达行尾下一个位置是 [i+1,0]
  bool backtrack(vector<vector<char>> &board, int i, int j) {
    int r = 9, l = 9; // 9*9 矩阵
    if (i == r)  // 全部遍历完了，成功
      return true;
    if (j == l)  // 一行遍历完了，跳转到下一行
      return backtrack(board, i + 1, 0);
    if (board[i][j] != '.')  // 当前节点有值，下一个
      return backtrack(board, i, j + 1);

    // 尝试当前位置上所有可能的取值 1～9
    for (char ch = '1'; ch <= '9'; ch++) {
      if (!isVaild(board, i, j, ch)) { // 判断当前取值是否符合条件
        continue;
      }

      board[i][j] = ch;
      if (backtrack(board, i, j + 1)) // 找到一个可行解就返回
        return true;
      board[i][j] = '.'; // 回溯
    }
    // 该位置上所有的取值都不行，需要回溯
    return false;
  }
  // 判断是否 target 作为 board[i][j] 是否可行
  bool isVaild(vector<vector<char>> &board, int i, int j, char target) {
    for (int k = 0; k < 9; k++) { // 行列不重复
      if (board[i][k] == target) return false;
      if (board[k][j] == target) return false;
    }
    // 3*3 方格不重复
    int ii = (i / 3) * 3, jj = (j / 3) * 3;
    for (int m = ii; m < ii + 3; m++) {
      for (int n = jj; n < jj + 3; n++) {
        if (board[m][n] == target) return false;
      }
    }
    return true;
  }
};

/**
 * 方法二：位置哈希
 * 参考 36 题，利用哈希表判断数字是否合法，合法的才能进一步回溯
 */
class Solution {
 public:
  void solveSudoku(vector<vector<char>> &board) {
    vector<vector<bool>> row(9, vector<bool>(9));
    vector<vector<bool>> col(9, vector<bool>(9));
    vector<vector<bool>> block(9, vector<bool>(9));

    // 已经确定的位置先记录
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] == '.') continue;
        int k = board[i][j] - '1';
        int b = i / 3 * 3 + j / 3;
        row[i][k] = true;
        col[j][k] = true;
        block[b][k] = true;
      }
    }

    backtrack(board, 0, 0, row, col, block);
  }
  bool backtrack(vector<vector<char>> &board, int i, int j,
                 vector<vector<bool>> &row, vector<vector<bool>> &col,
                 vector<vector<bool>> &block) {
    if (i >= 9) {
      return true;
    }

    // 下一个位置
    int nexti = i;
    int nextj = j + 1;
    if (nextj >= 9) {
      nexti++;
      nextj = 0;
    }

    // 固定的位置，直接跳到下一个位置
    if (board[i][j] != '.') {
      return backtrack(board, nexti, nextj, row, col, block);
    }

    int b = i / 3 * 3 + j / 3;
    for (int k = 0; k < 9; k++) {
      // 跳过不合法的值
      if (row[i][k] || col[j][k] || block[b][k]) continue;

      row[i][k] = true;
      col[j][k] = true;
      block[b][k] = true;
      board[i][j] = k + '1';

      if (backtrack(board, nexti, nextj, row, col, block)) return true;
      // 回溯
      row[i][k] = false;
      col[j][k] = false;
      block[b][k] = false;
      board[i][j] = '.';
    }

    return false;
  }
};