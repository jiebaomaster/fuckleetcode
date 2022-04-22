/**
 * https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/
 * 将字符串前k个元素移动到数组末尾
 * 
 * 先各局部翻转，再翻转整体
 */
class Solution {
 public:
  string reverseLeftWords(string s, int n) {
    reverse(s.begin(), s.begin() + n);
    reverse(s.begin() + n, s.end());
    reverse(s.begin(), s.end());
    return s;
  }
};