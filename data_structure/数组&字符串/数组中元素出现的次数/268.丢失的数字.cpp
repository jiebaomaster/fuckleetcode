/**
 * https://leetcode-cn.com/problems/missing-number/
 * https://labuladong.github.io/algo/4/29/117/
 * 思路来自于 136.只出现一次的数字，异或运算的性质 n ^ n => 0
 * 现 [0~k-1,k+1~n] 共 n 个数保存在 nums[0~n-1] 中，则可构造数组 [0~n, 0~k-1, k+1~n]，
 * 其中除了缺失的 k 只出现了一次以外，其余的数都出现了两次，则将构造数组所有元素异或即可得缺失的 k
 */
class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    int ret = 0;
    for (int i = 0; i < nums.size(); i++) {
      ret ^= i ^ nums[i];
    } 
    return ret ^ nums.size();
  }
};