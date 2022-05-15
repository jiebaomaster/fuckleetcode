class Solution {
 public:
  // 每个数字对应的备选字母
  vector<string> candidate = {"abc", "def",  "ghi", "jkl",
                              "mno", "pqrs", "tuv", "wxyz"};
  vector<string> res;
  vector<string> letterCombinations(string digits) {
    if (digits.size() == 0) return res;

    string track;
    dfs(0, track, digits);
    return res;
  }
  void dfs(int index, string &track, string &digits) {
    if (index == digits.size()) {
      res.push_back(track);
      return;
    }

    // 由当前的数字确定备选字母
    int t = digits[index] - '2';
    string &cur = candidate[t];
    // 回溯选择每一个备选字母
    for (int i = 0; i < cur.size(); i++) {
      track.push_back(cur[i]);
      dfs(index + 1, track, digits);
      // 回溯
      track.pop_back();
    }
  }
};