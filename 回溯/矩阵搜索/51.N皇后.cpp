/**
 * https://leetcode-cn.com/problems/n-queens/
 * https://labuladong.gitee.io/algo/4/29/104/
 */
class Solution {
 public:
  vector<vector<string>> res;  // 结果集
  vector<string> tracking;     // 路径

  vector<vector<string>> solveNQueens(int n) {
    vector<string> tracking(n, string(n, '.'));
    back_tracking(0, n, tracking);
    return res;
  };

  /**
   * @brief 求第 i 行放置 Q 的可行位置
   */
  void back_tracking(int i, int n, vector<string> &tracking) {
    if (i == n) {  // 满足结束条件，到达这里的一定是合法的
      res.push_back(tracking);
      return;
    }

    for (int j = 0; j < n; j++) { // 遍历第 i 行的所有位置 
      if (!isValid(tracking, i, j, n)) // 判断当前位置是否能放 Q
        continue;
      tracking[i][j] = 'Q';
      back_tracking(i + 1, n, tracking);
      tracking[i][j] = '.';
    }
  };

  /**
   * @brief 判断 tracking[i][j] 处是否能放 Q
   * 因为皇后是一行一行从上往下放的，所以左下方，右下方和正下方不用检查（还没放皇后）；
   * 因为一行只会放一个皇后，所以每行不用检查。也就是最后只用检查上面，左上，右上三个方向。
   */
  bool isValid(vector<string> &tracking, int i, int j, int n) {
    for (int k = 0; k < i; k++)  // 上方
      if (tracking[k][j] == 'Q') return false;

    for (int k = 1; i - k >= 0 && j - k >= 0; k++)  // 左上
      if (tracking[i - k][j - k] == 'Q') return false;

    for (int k = 1; i - k >= 0 && j + k < n; k++)  // 右上
      if (tracking[i - k][j + k] == 'Q') return false;

    return true;
  };
};