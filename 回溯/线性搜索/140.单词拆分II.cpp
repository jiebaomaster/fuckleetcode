/**
 * https://leetcode.cn/problems/word-break-ii/
 * 求所有方案，回溯
 */
class Solution {
 public:
  vector<string> res;
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    vector<string> track;
    backtrace(s, 0, wordDict, track);
    return res;
  }

  void backtrace(string& s, int i, vector<string>& wordDict,
                 vector<string>& track) {
    if (i == s.size()) { // 匹配完成，恢复字符串并加入结果集
      string ss;
      for (auto& t : track) ss += t + " ";
      ss.resize(ss.size() - 1);
      res.push_back(ss);
      return;
    }

    for (auto& w : wordDict) {
      // 若 w 可以匹配一部分，选择 w，dfs 向下
      if (s.substr(i, w.size()) == w) {
        track.push_back(w);
        backtrace(s, i + w.size(), wordDict, track);
        track.pop_back();
      }
    }
  }
};