/**
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/
 * https://labuladong.gitbook.io/algo/mu-lu-ye-3/mu-lu-ye-2/yuan-di-xiu-gai-shu-zu#you-xu-shu-zu-lian-biao-qu-zhong
 */
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() < 2) return nums.size(); // size 为 0 或 1，不需要去重

    // 快慢指针
    // 因为数组有序，所以慢指针保存的是最大的不重复数字的位置
    int low = 0, fast = 1;
    while (fast < nums.size()) { // 遍历整个数组
      if (nums[fast] != nums[low]) { // 每次遇到不相同的，储存到慢指针的下一个位置
        nums[++low] = nums[fast];
      }
      fast++;
    }
    return low + 1; // 去重后的数组尾 [0, low]
  }
};