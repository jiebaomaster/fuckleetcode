/**
 * https://leetcode.cn/problems/additive-number/
 * 遍历所有第一第二个数的组合，验证是否是累加数
 *
 * 方法一：正向验证，从前往后遍历字符串
 *
 */
class Solution {
 public:
  bool isAdditiveNumber(string num) {
    int n = num.size();
    // 遍历所有第一第二个数的组合，验证是否是累加数
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n - 1; j++) {
        // 第一个数 [0,i]，第二个数 [i+1,j]
        if (valid(num, 0, i, i + 1, j)) return true;
      }
    }
    return false;
  }

  bool valid(string &num, int ll, int lr, int rl, int rr) {
    // 不能有 0 开头的数
    if ((num[ll] == '0' && ll != lr) || (num[rl] == '0' && rl != rr))
      return false;
    // 这一次已经是结尾了，说明整个字符串符和要求
    if (rr + 1 == num.size()) return true;

    long n1 = stol(num.substr(ll, lr - ll + 1));
    long n2 = stol(num.substr(rl, rr - rl + 1));
    int b = max(lr - ll + 1, rr - rl + 1);  // n1 和 n2 的位数最大值
    // sum = n1 + n2 的位数可能是 b 和 b+1
    // 判断 sum 位数是 b 的情况
    long sum = stol(num.substr(rr + 1, b));
    if (n1 + n2 == sum) {
      return valid(num, rl, rr, rr + 1, rr + b);
    }
    // 判断 sum 位数是 b+1 的情况
    b++;
    sum = stol(num.substr(rr + 1, b));
    if (n1 + n2 == sum) {
      return valid(num, rl, rr, rr + 1, rr + b);
    }
    return false;
  }
};

/**
 * 方法二：反向验证
 * 直接生成 a b 构成的正确的累加数字符串，判断和原字符串是否相等
 */
class Solution {
 public:
  bool isAdditiveNumber(string num) {
    int n = num.size();
    // 遍历所有第一第二个数的组合，验证是否是累加数
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n - 1; j++) {
        // 第一个数 [0,i]，第二个数 [i+1,j]
        if (valid(num, 0, i, i + 1, j)) return true;
      }
    }
    return false;
  }

  bool valid(string &num, int ll, int lr, int rl, int rr) {
    // 不能有 0 开头的数
    if ((num[ll] == '0' && ll != lr) || (num[rl] == '0' && rl != rr))
      return false;

    long n1 = stol(num.substr(ll, lr - ll + 1));
    long n2 = stol(num.substr(rl, rr - rl + 1));

    string cur = num.substr(0, rr + 1);
    // 生成 n1 n2 构成的正确的累加数字符串，长度不能超过源字符串
    while (cur.size() < num.size()) {
      long sum = n1 + n2;
      cur += to_string(sum);
      n1 = n2;
      n2 = sum;
    }
    // 判断源字符串是否与生成的字符串相等
    return cur.size() == num.size() && cur == num;
  }
};