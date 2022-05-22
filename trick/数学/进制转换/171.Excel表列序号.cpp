/**
 * https://leetcode.cn/problems/excel-sheet-column-number/
 * 26进制转10进制
 */
class Solution {
 public:
  int titleToNumber(string columnTitle) {
    long res = 0;
    for (char c : columnTitle) {
      res = res * 26 + c + 1 - 'A';
    }
    return res;
  }
};