/**
 * 
 * https://leetcode.cn/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof/
 * https://leetcode.cn/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof/solution/mian-shi-ti-65-bu-yong-jia-jian-cheng-chu-zuo-ji-7/
 * 用位运算模拟加法
 * （和 s ）=（非进位和 n ）+（进位 c ）
 * ^ 亦或 相当于 无进位的求和
 * & 与 相当于求每位的进位数
 * 则最终公式为（a^b) ^ ((a&b)<<1) 即：每次无进位求 + 每次得到的进位数
 * 因为一次相加可能会产生新的进位，所以要循环求和直到没有进位为止
 */
class Solution {
 public:
  int add(int a, int b) {
    while (b) {
      // c++不支持负值左移，需要强制转换为无符号数
      int c = ((unsigned int)(a & b)) << 1; // 进位
      a ^= b; // 求和
      b = c; // 更新进位
    }
    return a;
  }
};