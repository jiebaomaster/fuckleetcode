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