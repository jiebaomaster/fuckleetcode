/**
 * https://leetcode-cn.com/problems/jump-game/
 * https://labuladong.gitbook.io/algo/mu-lu-ye-2/mu-lu-ye-3/tiao-yue-you-xi#jump-game-i
 * 每次跳几步无所谓，关键在于可跳的覆盖范围！不一定非要明确一次究竟跳几步，每次取最大的跳跃步数，
 * 这个就是可以跳跃的覆盖范围。这个范围内，别管是怎么跳的，反正一定可以跳过来。
 * 那么这个问题就转化为跳跃覆盖范围究竟可不可以覆盖到终点！
 */
class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int maxstep = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
      // 每次移动取最大跳跃步数（得到最大的覆盖范围），每移动一个单位，就更新最大覆盖范围
      maxstep = max(maxstep, i + nums[i]);
      if (maxstep < i + 1) return false; // 覆盖范围不足以跳到下一步了，说明不能到达终点
    }
    return true;
  }
};