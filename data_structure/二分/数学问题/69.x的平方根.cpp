/**
 * https://leetcode-cn.com/problems/sqrtx/
 * 查找1～x中第一个 k {k^2 >= x}
 * 
 * 方法一：普通二分
 */
class Solution {
 public:
  int mySqrt(int x) {
    int l = 0, r = x;
    while (l < r) {
      int mid = l + (r - l) / 2;
      if ((long long)mid * mid <= x)
        l = mid + 1;
      else
        r = mid;
    }
    // 取下界
    return (long long)l * l == x ? l : l - 1;
  }
};

/**
 * 方法二：带精度的二分
 */
class Solution1 {
 public:
  int mySqrt(int x) {
    if (x == 1) return 1;
    double eps = 1e-7;  // 可自定义的精度
    double l = 0, r = x;
    while (r - l > 1e-7) { // 迭代直到满足精度要求
      double mid = l + (r - l) / 2;
      if (mid * mid < x)
        l = mid;
      else
        r = mid;
    }
    /**
     * 此时 mid 在 sqrt(x) 的左边或右边都有可能，当 sqrt(x) 是一个整数
     * 且 mid 在其左边时对 mid 取下界就不正确了，所以这里对 r 取下界，
     * 因为 r 总在 sqrt(x) 的右边
     */
    return int(r);
  }
};

/**
 * 方法三：牛顿迭代，不停做曲线的切线逼近零点
 * https://leetcode-cn.com/problems/sqrtx/solution/niu-dun-die-dai-fa-by-loafer/
 * 求 sqrt(a) 相当于求 y=x^2-a 的零点
 * 取 x0=a，过曲线上一点 (x0, x0^2-x0) 的切线为 C1
 * 则 C1 与 x 轴的交点为 x1=(x0 + a/x0)/2，x1 比 x0 更接近零点
 * 令 x0=x1, 继续做切线，直到满足精度条件
 */
class Solution2 {
 public:
  int mySqrt(int x) {
    if (x == 0) // 0 不能作为除数
      return 0;

    double x0 = x, x1;
    double eps = 1e-5;
    while (1) {
      // 求切线与 x 轴的交点
      x1 = (x0 + x / x0) / 2;
      if (x0 - x1 < eps) // 判断是否满足精度要求
        break;

      x0 = x1;
    }
    return (int)x0;
  }
};