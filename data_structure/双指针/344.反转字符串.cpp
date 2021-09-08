/**
 * https://leetcode-cn.com/problems/reverse-string/
 * https://labuladong.gitbook.io/algo/mu-lu-ye-1/mu-lu-ye-4/shuang-zhi-zhen-ji-qiao#er-zuo-you-zhi-zhen-de-chang-yong-suan-fa
 */
class Solution {
 public:
  void reverseString(vector<char>& s) {
    // 首尾指针逼近法
    int left = 0, right = s.size() - 1;
    char tmp;
    while (left < right) {
      // 交互首尾指针指向的字符
      tmp = s[left];
      s[left] = s[right];
      s[right] = tmp;
      left++;
      right--;
    }
  }
};