/**
 * https://leetcode-cn.com/problems/reverse-integer/
 * 这一题不能使用 long long，所以要在计算每一位时判断是否可能溢出
 */
class Solution {
 public:
  int reverse(int x) {
    int res = 0;
    while (x) {
      // 判断此次进位是否会造成溢出
      if (res > INT_MAX / 10 || res < INT_MIN / 10) 
        return 0;
      // res进一位，加上末位
      res = res * 10 + x % 10;
      x /= 10;
    }
    return res;
  }
};