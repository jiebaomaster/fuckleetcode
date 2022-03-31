/**
 * https://leetcode-cn.com/problems/first-missing-positive/
 * https://leetcode-cn.com/problems/first-missing-positive/solution/que-shi-de-di-yi-ge-zheng-shu-by-leetcode-solution/
 * 找出一个未排序的整数数组 nums 中没有出现的最小的正整数
 * 最简单的方法就是用一个 hash 表存数组中的所有数，然后遍历正整数看 hash
 * 表中是否存在
 *
 * 方法一：将出现过的数作为下标，给该下标上的数打上标记
 */
class Solution {
 public:
  int firstMissingPositive(vector<int>& nums) {
    // 把 [1,size] 之外的数设置为无效数
    // 即去除负数，就可以把是否是负数作为标记
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] <= 0 || nums[i] > nums.size()) {
        nums[i] = nums.size() + 1;
      }
    }
    // 把有效的数作为下标，该下标上的数设置为负数，表示该下标的值有出现在数组中
    for (int i = 0; i < nums.size(); i++) {
      int n = abs(nums[i]);
      if (n <= nums.size()) {  // 有效的数
        if (nums[n - 1] > 0) nums[n - 1] *= -1;
      }
    }
    // 找到第一个大于 0 的，即该下标的值没有出现在数组中
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > 0) return i + 1;
    }
    // 没找到大于 0 的，说明 [1,size] 都出现在数组中了，
    // 则没出现过的最小正整数为 size+1
    return nums.size() + 1;
  }
};

/**
 * 方法二：原地哈希
 * 每次交换使得一个位置完成了原地哈希
 */
class Solution {
 public:
  int firstMissingPositive(vector<int>& nums) {
    for (int i = 0; i < nums.size();) {
      if (nums[i] > 0 && nums[i] <= nums.size() // 在[1,size] 内
        && nums[i] != nums[nums[i] - 1]) // 原地 hash 还没完成
        // 通过交换使得下标为 nums[i] - 1] 的位置完成了原地hash
        swap(nums[i], nums[nums[i] - 1]);
      else
        i++;
    }
    // 找到第一个没有完成原地哈希的，即该下标的值没有出现在数组中
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != i + 1) return i + 1;
    }
    return nums.size() + 1;
  }
};