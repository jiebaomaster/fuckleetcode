/**
 * https://leetcode-cn.com/problems/set-mismatch/
 * 集合 s 包含从 1 到 n 的整数。集合里面某一个数字复制了成了集合里面的另外一个数
 * 字的值，导致集合 丢失了一个数字 并且 有一个数字重复，求缺失数和重复数
 * 最简单就是用一个 O(n) 的空间统计出现次数，这里介绍不需要额外空间的解法
 * 
 * [1~k, k+1~m-1, k, m-1~n] 求缺失数 m 和重复数 k
 * 思路来自 260.只出现一次的数字III，分组求这两个数
 * 在原数组中添加 1～n 构造数组 [1~n, 1~k, k+1~m-1, k, m-1~n]
 * 则数组中，缺失数 m 出现了 1 次，重复数 k 出现了 1+2=3 次，由异或的性质可知将
 * 构造数组中所有元素异或得出非零数 m^k，则可以根据数的某个非 0 位将构造数组中的元
 * 素分成两组，m 和 k 必不在一个组，且组中其余数出现 2 次，自此问题转化为：
 * 数组中某个元素只出现一次，其余每个元素均出现两次，找出那个只出现了一次的元素。
 */
class Solution {
 public:
  vector<int> findErrorNums(vector<int>& nums) {
    int target = 0; // 求 m^k
    // 构造数组 s[i, nums[i]]
    for (int i = 1; i <= nums.size(); i++) {
      target ^= i ^ nums[i - 1];
    }
    int mask = 1; // 求第一个非零位
    while (target % 2 == 0) {
      mask <<= 1;
      target >>= 1;
    }
    int num1 = 0, num2 = 0; 
    // 将 i 和 nums[i] 进行分组
    for (int i = 1; i <= nums.size(); i++) {
      if (i & mask) {
        num1 ^= i;
      } else {
        num2 ^= i;
      }
      if (nums[i - 1] & mask) {
        num1 ^= nums[i - 1];
      } else {
        num2 ^= nums[i - 1];
      }
    }
    // 确认排序，num1 应该是重复数
    for (int i = 0; i < nums.size(); i++) {
      if (num2 == nums[i]) {
        swap(num1, num2);
        break;
      }
    }
    // {重复数, 缺失数}
    return {num1, num2};
  }
};