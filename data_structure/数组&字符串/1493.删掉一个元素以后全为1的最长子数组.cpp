/**
 * https://leetcode.cn/problems/longest-subarray-of-1s-after-deleting-one-element/
 * 
 */
class Solution {
 public:
  int longestSubarray(vector<int>& nums) {
    int pre = 0; // 上一段 1 的个数
    int cur = 0; // 当前段 1 的个数
    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 0) { // 遇到 0，更新上一段
        pre = cur;
        cur = 0;
      } else { // 遇到 1，累加当前段
        cur++;
        // 判断是否需要更新最大值
        if (cur + pre > res) res = cur + pre;
      }
    }
    // 源数组全部都是 1，必须要删除一个
    if (cur == nums.size()) res = cur - 1;
    return res;
  }
};