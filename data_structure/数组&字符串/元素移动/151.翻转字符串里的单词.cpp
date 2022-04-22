/**
 * https://leetcode-cn.com/problems/reverse-words-in-a-string/
 * https://programmercarl.com/0151.%E7%BF%BB%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2%E9%87%8C%E7%9A%84%E5%8D%95%E8%AF%8D.html#%E5%85%B6%E4%BB%96%E8%AF%AD%E8%A8%80%E7%89%88%E6%9C%AC
 * 基本思路是先翻转整个字符串，再翻转字符串中的每个单词
 */
class Solution {
 public:
  string reverseWords(string s) {
    // 1. 去除所有多余的空格
    removeExtraSpace(s);
    // 2. 翻转整个字符串
    reverse(s, 0, s.size() - 1);
    // 3. 翻转字符串中的每个单词
    int slow = 0,  // 指向单词的开始索引
        fast = 0;
    while (fast < s.size()) {
      if (s[fast] == ' ') { // 碰到空格说明找到一个单词
        reverse(s, slow, fast - 1);
        fast++;
        slow = fast;
      } else {
        fast++;
      }
    }
    // 最后的单词后面没有空格，需要在循环外处理
    reverse(s, slow, s.size() - 1);
    return s;
  }
  // 不能使用 erase 删除元素，因为 erase 会移动元素，时间复杂度为 O(n)
  // 先将所有保留元素移动到字符串开头的，再使用 resize 删除所有多余的部分
  void removeExtraSpace(string &s) {
    // 去除前导空格
    int fast = 0,  // 不停向前移动，指向当前正在处理的元素
        slow = 0;  // 指向字符串中当前可放置元素的位置
    while (fast < s.size() && s[fast] == ' ') {
      fast++;
    }
    // 去除单词中间的多余空格
    // 此时 fast 指向 s 中第一个不为空格的字符
    while (fast < s.size()) {
      // 跳过重复的空格
      if (fast > 0 && s[fast] == s[fast - 1] && s[fast - 1] == ' ') {
        fast++;
      } else {
        // 一般情况下，将元素向前移动
        s[slow++] = s[fast++];
      }
    }
    // 去除后面多余的字符
    // 如果原字符串末尾有空格，则最后一个空格也会被认为是需要保留的，
    // 即 slow 指向最后一个空格之后的位置，需要去掉最后一个多余的空格
    if (slow > 0 && s[slow - 1] == ' ') 
      s.resize(slow - 1);
    else
      s.resize(slow);
  }
  void reverse(string &s, int l, int r) {
    for (; l < r; l++, r--) {
      swap(s[l], s[r]);
    }
  }
};