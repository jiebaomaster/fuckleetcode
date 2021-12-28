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
class Solution1 {
 public:
  vector<string> res;
  vector<string> generateParenthesis(int n) {
    string track;
    dfs(track, 0, n * 2, 0, 0);
    return res;
  }

  // i 记录"("的数量，j 记录")"的数量
  void dfs(string &track, int index, int n, int i, int j) {
    if (index == n) { // 括号序列总是合法的
      res.push_back(track);
      return;
    }
    if (i < n / 2) { // 最多有 n/2 个"("
      track.push_back('(');
      dfs(track, index + 1, n, i + 1, j);
      track.pop_back();
    }

    if (i > j) { // 先有"("才能有")"
      track.push_back(')');
      dfs(track, index + 1, n, i, j + 1);
      track.pop_back();
    }
  }
};