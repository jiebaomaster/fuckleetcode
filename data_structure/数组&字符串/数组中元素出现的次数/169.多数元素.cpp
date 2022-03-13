/**
 * https://leetcode-cn.com/problems/majority-element/
 * 找到数组中出现次数大于 n/2 的数
 * 摩尔投票法，核心就是对拼消耗
 * 将数组中目标数和非目标数一一抵消，剩下的必定是目标数
 * 先假设第一个数过半数并设 cnt=1；
 * 遍历后面的数如果相同则 cnt++，不同则 cnt--，当 cnt 为 0 时则更换新的数字为候选数
 */
class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int cnt = 1;
    int res = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] == res) {
        cnt++;
      } else {
        if (cnt-- == 0) {
          res = nums[i];
          cnt = 1;
        }
      }
    }
    return res;
  }
};