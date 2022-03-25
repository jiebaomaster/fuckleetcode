/**
 * https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/
 * 基础矩阵搜索
 */
class Solution {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    // 记录是否访问过，防止走回头路
    vector<vector<bool>> used(board.size(),
                              vector<bool>(board[0].size(), false));
    // 尝试以每一个节点为起点
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        if (dfs(board, word, used, i, j, 0)) return true;
      }
    }
    return false;
  }

  bool dfs(vector<vector<char>>& board, string& s, vector<vector<bool>>& used,
           int i, int j, int cur) {
    if (s.size() == cur) return true;
    if (i >= 0 && i < board.size() && j >= 0 && j < board[0].size() &&
        !used[i][j] && s[cur] == board[i][j]) {
      cur++;
      used[i][j] = true;
      // 往上下左右四个方向继续搜索
      bool ret = dfs(board, s, used, i - 1, j, cur) ||
                 dfs(board, s, used, i + 1, j, cur) ||
                 dfs(board, s, used, i, j - 1, cur) ||
                 dfs(board, s, used, i, j + 1, cur);
      // 回溯
      used[i][j] = false;

      return ret;
    }
    return false;
  }
};