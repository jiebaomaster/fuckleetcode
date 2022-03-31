/**
 * https://leetcode-cn.com/problems/surrounded-regions/
 * 只有和边界相邻的 O 才不能被覆盖
 * 标记所有和边界相邻的 O，再遍历一次矩阵把所有的 O 设为 X
 */
class Solution {
 public:
  void dfs(vector<vector<char>>& board, int i, int j) {
    if (i >= 0 && i < board.size() && j >= 0 && j < board[0].size() &&
        board[i][j] == 'O') {
      board[i][j] = '-';
      dfs(board, i - 1, j);
      dfs(board, i + 1, j);
      dfs(board, i, j - 1);
      dfs(board, i, j + 1);
    }
  }
  void solve(vector<vector<char>>& board) {
    int n = board.size();
    int m = board[0].size();

    for (int j = 0; j < m; j++) {
      dfs(board, 0, j);
      dfs(board, n - 1, j);
    }
    for (int i = 1; i < n - 1; i++) {
      dfs(board, i, 0);
      dfs(board, i, m - 1);
    }

    // 恢复
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (board[i][j] == 'O') {
          board[i][j] = 'X';
        } else if (board[i][j] == '-') {
          board[i][j] = 'O';
        }
      }
    }
  }
};