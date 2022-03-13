/**
 * https://leetcode-cn.com/problems/compare-version-numbers/
 */
class Solution {
 public:
  int compareVersion(string version1, string version2) {
    // 双指针法提取处每次要比较的字符串
    int slow1 = 0, fast1 = 0;
    int slow2 = 0, fast2 = 0;
    int n1 = version1.size();
    int n2 = version2.size();

    while (fast1 < n1 || fast2 < n2) {
      // 提取出要比较的字符串，去除前导 0
      while (slow1 < n1 && version1[slow1] == '0') slow1++;
      while (fast1 < n1 && version1[fast1] != '.') fast1++;
      while (slow2 < n2 && version2[slow2] == '0') slow2++;
      while (fast2 < n2 && version2[fast2] != '.') fast2++;
      // [slow1, fast1) 和 [slow2, fast2) 比较
      // 位数更多的数字显然是更大的
      if (fast1 - slow1 < fast2 - slow2)
        return -1;
      else if (fast1 - slow1 > fast2 - slow2)
        return 1;
      // 位数一样的数字，从高位到低位比较每一个字符
      while (slow1 < fast1) {
        if (version1[slow1] < version2[slow2])
          return -1;
        else if (version1[slow1] > version2[slow2])
          return 1;
        slow1++;
        slow2++;
      }
      // 下一次比较从 "." 后面的字符开始
      fast1++;
      fast2++;
      slow1 = fast1;
      slow2 = fast2;
    }
    return 0;
  }
};