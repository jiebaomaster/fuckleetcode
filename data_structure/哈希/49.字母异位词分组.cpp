/**
 * https://leetcode.cn/problems/group-anagrams/
 * 
 * 方法一：排序键
 * 字母异位词排序之后所得的字符串相同，所以可以把排序后的字符串作为键
 * 
 */
class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> sv;
    for (auto& s : strs) {
      auto cp = s;
      sort(cp.begin(), cp.end());
      sv[cp].push_back(s);
    }
    vector<vector<string>> res;
    for (auto& [s, v] : sv) {
      res.push_back(v);
    }
    return res;
  }
};

/**
 * d
 */