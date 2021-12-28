/**
 * https://leetcode-cn.com/problems/letter-case-permutation/
 * 本题实际上在求字母的子集，子集中的元素为需要进行大小写转换的元素
 */
class Solution {
 public:
  vector<string> res;
  vector<string> letterCasePermutation(string s) {
    string track;
    dfs(track, s, 0);
    return res;
  }

  // 考虑 s[index] 是否应该进行大小写转化
  void dfs(string &track, string &s, int index) {
    if (index == s.size()) { // s 中所有的字符都考虑完了
      res.push_back(track);
      return;
    }

    // 对于当前字符，如果是字母，可以进行大小写转换
    if (s[index] >= 'a' && s[index] <= 'z') {
      track.push_back(toupper(s[index]));
      dfs(track, s, index + 1);
      track.pop_back();
    } else if (s[index] >= 'A' && s[index] <= 'Z') {
      track.push_back(tolower(s[index]));
      dfs(track, s, index + 1);
      track.pop_back();
    }

    // 不进行大小写转换
    track.push_back(s[index]);
    dfs(track, s, index + 1);
    track.pop_back();
  }
};