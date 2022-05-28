/**
 * https://leetcode.cn/problems/sentence-similarity/
 * 
 */
class Solution {
 public:
  bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2,
                           vector<vector<string>>& similarPairs) {
    if (sentence1.size() != sentence2.size()) return false;
    int n = sentence1.size();
    // 用一个 hash 表维护相似性，注意相似关系具有反身性
    unordered_multimap<string, string> ss;
    for (int i = 0; i < similarPairs.size(); i++) {
      ss.insert({similarPairs[i][0], similarPairs[i][1]});
      ss.insert({similarPairs[i][1], similarPairs[i][0]});
    }
    for (int i = 0; i < n; i++) {
      // 相等的直接跳过
      if (sentence1[i] == sentence2[i]) continue;
      // 判断是否相似
      auto range = ss.equal_range(sentence1[i]);
      auto it = range.first;
      for (; it != range.second; ++it) {
        if (it->second == sentence2[i]) break;
      }
      if (it == range.second) return false;
    }
    return true;
  }
};