/**
 * https://leetcode-cn.com/problems/valid-palindrome/
 */
class Solution {
 public:
  bool isPalindrome(string s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
      // 跳过所有的非数字和非字母的字符
      while (l < r && !(isalpha(s[l]) || isdigit(s[l]))) l++;
      while (l < r && !(isalpha(s[r]) || isdigit(s[r]))) r--;
      if (isalpha(s[l]) && isalpha(s[r])) { // 字母可以忽略大小写
        if (tolower(s[l]) != tolower(s[r])) {
          return false;
        }
      } else if (s[l] != s[r])
        return false;
      l++;
      r--;
    }
    return true;
  }
};