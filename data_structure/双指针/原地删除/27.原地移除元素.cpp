/**
 * https://leetcode-cn.com/problems/remove-element/
 * https://labuladong.gitbook.io/algo/mu-lu-ye-3/mu-lu-ye-2/yuan-di-xiu-gai-shu-zu#yi-chu-yuan-su
 */
class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    if (nums.size() == 0) return 0;

    int slow = -1, fast = 0;
    while (fast < nums.size()) {
      if (val != nums[fast]) {
        nums[++slow] = nums[fast];
      }
      fast++;
    }

    return slow + 1;
  }
};