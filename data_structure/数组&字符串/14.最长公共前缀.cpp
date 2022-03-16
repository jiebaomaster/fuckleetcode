/**
 * https://leetcode-cn.com/problems/longest-common-prefix/
 * 方法一：纵向扫描，从下标0开始，判断每一个字符串的下标0，判断是否全部相同。
 * 直到遇到不全部相同的下标。时间复杂度为 O(n*m)
 */
class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    int cnt = 0;
    int i = 0;
    while (1) {  // 遍历字符串的每个下标
      char t = 0;
      for (int j = 0; j < strs.size(); j++) {  // 遍历每个字符串
        if (strs[j].size() <= i) {  // 达到某个字符串下标的最大值
          return strs[j].substr(0, i);
        }
        if (j == 0) {  // 记录第一个字符串的第 i 个下标的值
          t = strs[0][i];
          continue;
        } else if (strs[j - 1][i] != strs[j][i]) {  // 找到某个下标不相同
          return strs[j].substr(0, i);
        }
      }
      i++;  // 本下标的所有字符相同，判断下一个
    }
  }
};

/**
 * 方法二：排序法，将字符串按字典序排序的，取最大值和最小值的前缀
 */
class Solution1 {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    sort(strs.begin(), strs.end());
    int i = 0;
    for (; i < strs[0].size(); i++) {
      if (strs[0][i] != strs[strs.size() - 1][i]) break;
    }
    return strs[0].substr(0, i);
  }
};