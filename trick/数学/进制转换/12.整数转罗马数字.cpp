/**
 * https://leetcode.cn/problems/integer-to-roman/
 * 方法一：累加法，从小到大，计算每一个 10 进制位对应的罗马数字
 * 需要特殊处理 4 和 9
 */
class Solution {
 public:
  string intToRoman(int num) {
    string one = "IXCM";
    string five = "VLD";
    string res;
    int i = 0;
    while (num) {
      string t;
      int n = num % 10;
      if (n == 0) {
      } else if (n <= 3) {
        t = string(n, one[i]);
      } else if (n == 4) {
        t = string(1, one[i]) + five[i];
      } else if (n <= 8) {
        t = string(1, five[i]) + string(n - 5, one[i]);
      } else {  // 9
        t = string(1, one[i]) + string(1, one[i + 1]);
      }
      i++;
      num /= 10;
      res = t + res;
    }
    return res;
  }
};

/**
 * 方法二：累减法，从大到小，计算每一个 10 进制位对应的罗马数字
 */
class Solution {
 public:
  string intToRoman(int num) {
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string reps[] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                     "XL", "X",  "IX", "V",  "IV", "I"};

    string res;
    for (int i = 0; i < 13; i++) {
      while (num >= values[i]) {
        num -= values[i];
        res += reps[i];
      }
    }
    return res;
  }
};