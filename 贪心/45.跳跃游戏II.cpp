/**
 * https://leetcode-cn.com/problems/jump-game-ii/
 * https://labuladong.gitbook.io/algo/mu-lu-ye-2/mu-lu-ye-3/tiao-yue-you-xi#jump-game-ii
 */
class Solution {
 public:
  int jump(vector<int>& nums) {
    int res = 0;
    int farthest = 0, end = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
      farthest = max(farthest, nums[i] + i);
      if (end == i) { // 贪心，走到上一次覆盖的最远处
        res++;
        end = farthest;
      }
    }
    return res;
  }
};