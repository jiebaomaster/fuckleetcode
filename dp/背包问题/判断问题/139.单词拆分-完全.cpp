/**
 * https://leetcode-cn.com/problems/word-break/
 * https://programmercarl.com/0139.%E5%8D%95%E8%AF%8D%E6%8B%86%E5%88%86.html
 * 单词就是物品，字符串 s 就是背包，单词能否组成字符串 s，就是问物品能不能把背包装满。
 * 拆分时可以重复使用字典中的单词，即完全背包。
 * 拼接字符串时 word 的选择有顺序要求，类似排列数，可以使用 70.爬楼梯 的思想
 * 定义 dp[i] 表示 s[0~i] 是否可由 wordDict 中的字符串拼接出
 * 要求 dp[i]，将 s 分为两部分，prefix 和可选的 word
 * 则有 s[0 ~ i] = s[0 ~ i-word[k].size()] + word[k]，0<=k<wordDict.size()
 * 要想 dp[i] 为 true
 *   首先 prefix 部分要可选，即 dp[i - word[k].size()]=true
 *   其次 word 部分要在可选的字符串集合中，即 wordDict[k] == t
 */
class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    vector<bool> dp(s.size() + 1, false);

    dp[0] = true;
    for (int i = 1; i <= s.size(); i++) { // 遍历容量
      for (int k = 0; k < wordDict.size(); k++) { // 遍历物品
        // 选择字典中的每一个字符串作为 word 部分
        size_t wordLen = wordDict[k].size();
        if (i >= wordLen) {
          string t = s.substr(i - wordLen, wordLen);
          if (dp[i - wordLen]         // prefix 部分可选
              && wordDict[k] == t) {  // word 部分在字典中
            dp[i] = true;
            break; // 只要有一种情况满足即可
          }
        }
      }
    }
    return dp[s.size()];
  }
};

/**
 * 方法二：根据选择的单词进行回溯
 */
class Solution1 {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    return backTrace(s, 0, wordDict);
  }
  /**
   * @param index s[index...] 之后还未匹配
   */
  bool backTrace(string& s, int index, vector<string>& wordDict) {
    if (s.size() == index) { // 匹配到末尾说明匹配成功了
      return true;
    }
    // 给当前位置遍历所有可选的匹配项
    for (int i = 0; i < wordDict.size(); i++) {
      if (valid(s, index, wordDict[i])) { // 可匹配的话进入下个位置的匹配
        if (backTrace(s, index + wordDict[i].size(), wordDict)) return true;
      }
    }
    return false;
  }
  // 判断 c 是否可与 s[index...] 匹配
  bool valid(string& s, int index, string& c) {
    for (int j = 0; j < c.size(); j++) {
      if (index >= s.size() || s[index++] != c[j]) return false;
    }
    return true;
  }
};