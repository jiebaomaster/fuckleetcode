/**
 * https://leetcode.cn/problems/zigzag-conversion/
 * 直接模拟。
 * 因为最后的输出中不包含空格，所以这里不必真的在二维数组中模拟
 * 只需要记录每一行的字符
 */
class Solution {
 public:
  string convert(string s, int numRows) {
    if (numRows < 2) return s;
    vector<string> rows(numRows);
    int i = 0;
    int flag = -1;
    for (char c : s) {
      rows[i] += c; // 记录每一行的字符
      if (i == 0 || i == numRows - 1) {  // 发生转向
        flag = -flag;
      }
      i += flag;  // 移动行标
    }
    // 每一行加起来就是结果
    return accumulate(next(rows.begin()), rows.end(), *rows.begin());
  }
};