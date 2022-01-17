/**
 * https://leetcode-cn.com/problems/bulb-switcher/
 * 第 i 个灯泡的反转次数等于它所有因子（包括 1 和 i）的个数，一开始灯是灭的，所以只有反转奇数次才会变成亮的，
 * 即只有因子个数为奇数的灯泡序号才会亮，可以知道只有平方数的因子数为奇数
 * 比如 6=1*6=2*3，非平方数的因子总是成对出现的，而 4=1*4=2*2，平方数的平方根因子会只出现 1 次
 * 所以最终答案等于 n 以内（包括 n 和 1）的平方数数量，只要计算 sqrt(n) 即可
 */
class Solution {
 public:
  int bulbSwitch(int n) { 
    return sqrt(n);
  }
};