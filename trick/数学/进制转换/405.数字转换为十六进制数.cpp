/**
 * https://leetcode.cn/problems/convert-a-number-to-hexadecimal/
 * 10 进制转换为 16 进制字符串
 */
class Solution {
 public:
  string toHex(int num) {
    if (num == 0) return "0";

    string res;
    string hex = "0123456789abcdef";
    // res.size() < 8，处理负数补 1 的情况
    while (num && res.size() < 8) {
      // 0xf 取 num 的低 4 位，查表得16进制字符
      res = hex[num & 0xf] + res;
      // 左移4位，对于负数会补 1，自动处理补码
      num >>= 4;
    }
    return res;
  }
};