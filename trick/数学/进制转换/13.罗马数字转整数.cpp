/**
 * https://leetcode.cn/problems/roman-to-integer/
 * 方法一：反向遍历
 */
class Solution {
 public:
  int romanToInt(string s) {
    unordered_map<char, pair<int, char>> cnum = {
        {'I', {1, ' '}},   {'V', {5, 'I'}},   {'X', {10, 'I'}},
        {'L', {50, 'X'}},  {'C', {100, 'X'}}, {'D', {500, 'C'}},
        {'M', {1000, 'C'}}};

    int res = 0;
    for (int i = s.size() - 1; i >= 0;) {
      res += cnum[s[i]].first;
      // 向前看一个字符，如果前一个字符是需要减的情况，就进行一次减法
      if (i > 0 && s[i - 1] == cnum[s[i]].second) {
        res -= cnum[cnum[s[i]].second].first;
        i--;
      }
      i--;
    }
    return res;
  }
};

/**
 * 方法二：正向遍历
 */
class Solution {
 public:
  int romanToInt(string s) {
    unordered_map<char, int> cnum = {{'I', 1},   {'V', 5},   {'X', 10},
                                     {'L', 50},  {'C', 100}, {'D', 500},
                                     {'M', 1000}};

    int res = 0;
    for (int i = 0; i < s.size(); i++) {
      // 向前看一个字符，如果当前字符代表的值不小于其右边，就加上该值；否则就减去该值
      if (i != s.size() - 1 && cnum[s[i]] < cnum[s[i + 1]])
        res -= cnum[s[i]];
      else
        res += cnum[s[i]];
    }
    return res;
  }
};