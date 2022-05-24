/**
 * https://leetcode.cn/problems/valid-palindrome-ii/
 * 字符串可以删除一个，判断是否能构成回文
 * 当遇到不相等时提供一次删除机会，左右两边删除的情况不一样，都需要判断
 * 
 * 补充：如果是求删除 k 个是否可以组成回文串，可以转成动态规划求最长回文子序列长度，
 *      如果原长度 - 最长回文子序列长度 <=k 就可以组成
 */
class Solution {
 public:
  bool validPalindrome(string s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
      if (s[l] != s[r]) { // 当遇到不相等时提供一次删除机会
        return isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1);
      }
      l++;
      r--;
    }
    return true;
  }
  // 严格验证回文
  bool isPalindrome(string &s, int l, int r) {
    while (l < r) {
      if (s[l] != s[r]) {
        return false;
      }
      l++;
      r--;
    }
    return true;
  }
};