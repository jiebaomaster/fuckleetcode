/**
 * https://leetcode-cn.com/problems/generate-parentheses/
 * https://labuladong.gitee.io/algo/4/29/109/
 */
class Solution {
 public:
  vector<string> res;
  vector<string> generateParenthesis(int n) {
    string track;
    // n 对括号，即括号序列长度为 n*2
    backtrace(track, 0, n * 2);
    return res;
  }
  // 生成括号序列，考虑括号序列中的每一位
  void backtrace(string &track, int index, int n) {
    if (index == n) {
      if (isVaild(track)) res.push_back(track);
      return;
    }

    track.push_back('(');
    backtrace(track, index + 1, n);
    track.pop_back();


    track.push_back(')');
    backtrace(track, index + 1, n);
    track.pop_back();
  }

  // 判断括号序列是否合法，")"之前要有足够数量的"("
  bool isVaild(string &track) {
    int count = 0;
    for (char ch : track) {
      if (ch == '(') {
        count++;
      } else {
        if (count == 0) {
          return false;
        } else {
          count--;
        }
      }
    }
    if (count > 0) {
      return false;
    }
    return true;
  }
};

/**
 * 可以在通过控制 dfs 的过程使括号序列都是合法的，就不用最后去判断合法性了
 */
class Solution {
 public:
  vector<string> res;
  vector<string> generateParenthesis(int n) {
    string track;
    backtrace(track, n, 0, 0);
    return res;
  }
  /**
   * @param n 目标括号对数
   * @param l 左括号个数
   * @param r 右括号个数
   */
  void backtrace(string &track, int n, int l, int r) {
    if (n == l && n == r) {
      res.push_back(track);
      return;
    }

    if (r < n && l > r) { // 右括号个数不能超过左括号
      track.push_back(')');
      backtrace(track, n, l, r + 1);
      track.pop_back();
    }

    if (l < n) { // 左括号个数最多只能是 n
      track.push_back('(');
      backtrace(track, n, l + 1, r);
      track.pop_back();
    }
  }
};