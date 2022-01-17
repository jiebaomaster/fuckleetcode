/**
 * https://leetcode-cn.com/problems/single-number-ii/
 * 数组中某个元素只出现一次，其余每个元素均出现三次，找出那个只出现了一次的元素。
 * 
 * 将每个数想象成 32 位的二进制，对于每一位的二进制的 1 和 0 累加起来
 * 必然是 3N 或者 3N+1，为 3N 代表目标值在这一位没贡献，3N+1 代表目
 * 标值在这一位有贡献(=1)，然后将所有有贡献的位 | 起来就是结果。这样做
 * 的好处是如果题目改成 K 个一样，只需要把代码改成 cnt%k，很通用
 */
class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int cnt = 0;
    int mask = 1;
    int target = 0;
    for (int i = 0; i < 32; i++) {
      mask = 1 << i; // 当前统计的位数
      cnt = 0;
      // 统计所有数字的第 i 位
      for (int num : nums) {
        if ((num & mask) != 0) {
          cnt++;
        }
      }
      if (cnt % 3 == 1) {
        target |= mask;
      }
    }
    return target;
  }
};