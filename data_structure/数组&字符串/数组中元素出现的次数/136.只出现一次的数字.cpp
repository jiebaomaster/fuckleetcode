/**
 * https://leetcode-cn.com/problems/single-number/
 * 数组中某个元素只出现一次，其余每个元素均出现两次，找出那个只出现了一次的元素。
 * 异或的性质：
 * 1. 交换律：a ^ b ^ c <=> a ^ c ^ b
 * 2. 任何数于0异或为任何数 0 ^ n => n
 * 3. 相同的数异或为0: n ^ n => 0
 * 
 * 例如，nums = [2,3,2,4,4]
 * 2 ^ 3 ^ 2 ^ 4 ^ 4 => 2 ^ 2 ^ 4 ^ 4 ^ 3 => 0 ^ 0 ^3 => 3
 */
class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int target = 0;
    for (int n : nums) {
      target ^= n;
    }
    return target;
  }
};