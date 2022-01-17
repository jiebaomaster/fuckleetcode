/**
 * https://leetcode-cn.com/problems/single-number-iii/
 * 数组中有两个元素只出现一次，其余所有元素均出现两次。找出只出现一次的那两个元素
 * 先将全部数异或一次，得到的异或结果，结果必不为 0，选定结果的某个非 0 位，
 * 比如最高非 0 位。那么只出现一次的两个数中, 在这个位上一个为 0，一个为 1，
 * 由此可以根据这个非 0 位将数组中的元素分成两组，两个只出现一次的数被分入一组，
 * 且其余重复数都会被分入其中一组。自此问题转化为：
 * 数组中某个元素只出现一次，其余每个元素均出现两次，找出那个只出现了一次的元素。
 */
class Solution {
 public:
  vector<int> singleNumber(vector<int>& nums) {
    int target = 0;
    for (int i = 0; i < nums.size(); i++) { // 全部异或
      target ^= nums[i];
    }
    int mask = 1;
    while ((target & 1) == 0) { // 选定一个非 0 位
      target >>= 1;
      mask <<= 1;
    }
    int num1 = 0, num2 = 0;
    for (int i = 0; i < nums.size(); i++) { // 分组求只出现了一次的元素
      if (nums[i] & mask) {
        num1 ^= nums[i];
      } else {
        num2 ^= nums[i];
      }
    }
    return {num1, num2};
  }
};