/**
 * https://leetcode-cn.com/problems/multiply-strings/
 */
class Solution {
 public:
  string multiply(string num1, string num2) {
    // 暂存每一位的运算结果，n 位数乘 m 位数的结果最多可有 n+m 位
    vector<int> reverse_res(num1.size() + num2.size());
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    int join = 0;
    int tmp = 0;
    int x, y;  // x*y
    // num1 * num2，取 y=num2[i] 乘以 num1 的每一位 x
    for (int i = 0; i < num2.size(); i++) {
      join = 0;
      y = num2[i] - '0';
      for (int j = 0; j < num1.size(); j++) {
        x = num1[j] - '0';
         // 边算边叠加，临时计算结果需要加上本位上已经计算出来的数
        tmp = x * y + join + reverse_res[j + i];
        reverse_res[j + i] += tmp % 10; // 计算本位
        join = tmp / 10; // 计算进位
      }
      if (join) { // 最高位的进位单独处理
        reverse_res[num1.size() + i] = join;
      }
    }
    // 去除前导 0
    int i = reverse_res.size() - 1;
    while (i && reverse_res[i] == 0) {
      i--;
    }
    string res = "";
    // 拼接结果字符串
    for (; i >= 0; i--) {
      res += to_string(reverse_res[i]);
    }
    if (res == "") {
      res = "0";
    }
    return res;
  }
};