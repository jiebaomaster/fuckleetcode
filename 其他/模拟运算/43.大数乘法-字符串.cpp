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
        reverse_res[j + i] = tmp % 10; // 计算本位
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

/**
 * 乘法模拟，n1 * n2，n2 是更短的数，将 n2 的每一位乘以 n1，累加每一位的结果
 */
class Solution {
 public:
  string multiply(string num1, string num2) {
    // 符号和 0 在外边处理
    bool isNagitive = false;
    if (num1[0] == '-') {
      isNagitive = true;
      num1 = num1.substr(1);
    }
    if (num2[0] == '-') {
      isNagitive = !isNagitive;
      num2 = num2.substr(1);
    }
    if (num1[0] == '0' || num2[0] == '0') return "0";
    // 计算两个正数的乘法
    string res;
    if (num1 < num2) {
      res = doMultiply(num2, num1);
    } else {
      res = doMultiply(num1, num2);
    }
    return (isNagitive ? "-" : "") + res;
  }
  // lhs > rhs, lhs * rhs
  string doMultiply(string& lhs, string& rhs) {
    int n = lhs.size();
    int m = rhs.size();
    string res;

    for (int i = 0; i < m; i++) {
      int t = rhs[m - i - 1] - '0';
      string cur(i, '0');
      int c = 0;
      for (int j = n - 1; j >= 0 || c; j--) {
        if (j >= 0) c += t * (lhs[j] - '0');

        cur.push_back((c % 10) + '0');
        c /= 10;
      }
      reverse(cur.begin(), cur.end());
      res = add(res, cur);
    }
    return res;
  }

  string add(string& num1, string& num2) {
    int c = 0;
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    string res;
    while (i >= 0 || j >= 0 || c) {
      if (i >= 0) c += num1[i--] - '0';
      if (j >= 0) c += num2[j--] - '0';

      res.push_back(c % 10 + '0');
      c /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
  }
};