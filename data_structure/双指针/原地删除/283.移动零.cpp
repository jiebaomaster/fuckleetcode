/**
 * https://leetcode-cn.com/problems/move-zeroes/
 * https://labuladong.gitbook.io/algo/mu-lu-ye-3/mu-lu-ye-2/yuan-di-xiu-gai-shu-zu#yi-dong-ling
 * 题目让我们将所有 0 移到最后，其实就相当于移除 nums 中的所有 0，然后再把后面的元素都赋值为 0 即可。
 */ 
class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    if (nums.size() < 2) return;

    // 原地删除数组中所有的 0
    int slow = -1, fast = 0;
    while (fast < nums.size()) { 
      if (nums[fast] != 0) {
        nums[++slow] = nums[fast];
      }
      fast++;
    }
    
    // 将后面 (slow, nums.size()) 的元素全部赋值为 0
    for (slow++; slow < nums.size(); slow++) nums[slow] = 0;
  }
};