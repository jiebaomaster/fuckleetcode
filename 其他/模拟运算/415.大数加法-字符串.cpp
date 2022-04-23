/**
 * https://leetcode-cn.com/problems/add-strings/
 * 大数加法，字符串结构
 */
class Solution {
 public:
  string addStrings(string num1, string num2) {
    // 先将字符串逆序，使遍历每一位更简单
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    int join = 0;  // 进位
    int maxlen = max(num1.size(), num2.size());
    string res_str = "";  // 结果
    int tmp;              // 保存每一位计算结果的临时变量
    // 计算每一位
    for (int i = 0; i < maxlen; i++) {
      tmp = join;
      if (num1.size() > i) tmp += num1[i] - '0';
      if (num2.size() > i) tmp += num2[i] - '0';

      res_str = to_string(tmp % 10) + res_str;  // 拼接本位结果
      join = tmp / 10;                          // 计算本位进位
    }
    // 最后还有进位的话，在结果最前面添加 1
    if (join) {
      res_str = "1" + res_str;
    }
    return res_str;
  }
};

/**
 * 用逆向迭代器便利字符串，省去一开始的反转字符串
 */
class Solution1 {
 public:
  string addStrings(string num1, string num2) {
    int carry = 0;
    string ret;
    auto n1 = num1.rbegin(), n2 = num2.rbegin();
    while (n1 != num1.rend() || n2 != num2.rend()) {
      int tmp = carry;
      if (n1 != num1.rend()) {
        tmp += *n1 - '0';
        n1++;
      }
      if (n2 != num2.rend()) {
        tmp += *n2 - '0';
        n2++;
      }
      carry = tmp / 10;
      ret = to_string(tmp % 10) + ret;
    }
    if (carry) ret = "1" + ret;
    return ret;
  }
};