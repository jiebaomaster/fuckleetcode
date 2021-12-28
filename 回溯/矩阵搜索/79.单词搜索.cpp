/**
 * https://leetcode-cn.com/problems/word-search/
 * https://leetcode-cn.com/problems/word-search/solution/dan-ci-sou-suo-by-leetcode-solution/
 * 经典题，判断矩阵中是否存在某个符合要求的区域，dfs 有上下左右四个方向可选
 * 在一个二维矩阵中进行搜索，通常需要以矩阵中每一个点为起点，
 * DFS 往上下左右 4 个方向移动，注意访问标志的回溯
 */
class Solution {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    int m = board.size();
    int n = board[0].size();
    // 回溯中防止重复访问
    vector<vector<bool>> used(m, vector<bool>(n, false));
    // 以矩阵中每一个元素作为起点，搜索是否含有 word
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (dfs(board, used, m, n, i, j, word, 0)) { // 找到一个就退出
          return true;
        }

    return false;
  }

  // 判断从 board[i][j] 起点的矩阵中是否存在 word[index...len)
  bool dfs(vector<vector<char>>& board, vector<vector<bool>>& used, int m,
           int n, int i, int j, string& word, int index) {
    if (index == word.size()) // word 中的所有字母都找到了
      return true;

    if (i < 0 || i >= m ||  // 判断行坐标合法
        j < 0 || j >= n ||  // 判断列坐标合法
        used[i][j] ||       // 判断该点是否已使用
        word[index] != board[i][j]) // 判断当前点是否是要搜索的字母
      return false;

    used[i][j] = true;
    // 从 [i,j] 的上下左右四个方向中查找下一个字母，只要有一个符合就可以
    bool res = dfs(board, used, m, n, i, j + 1, word, index + 1) || // 上
              dfs(board, used, m, n, i, j - 1, word, index + 1) || // 下
              dfs(board, used, m, n, i + 1, j, word, index + 1) || // 右
              dfs(board, used, m, n, i - 1, j, word, index + 1);   // 左
    used[i][j] = false; // 回溯
    return res;
  }
};