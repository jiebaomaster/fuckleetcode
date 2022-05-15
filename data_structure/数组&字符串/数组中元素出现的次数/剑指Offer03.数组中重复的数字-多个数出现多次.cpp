/**
 * https://leetcode.cn/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/
 * 本题的解法很多，各有取舍
 *           时间      空间     是否改变源数组
 * 排序法   O(nlogn)  O(logn)       是
 * 哈希法     O(n)      O(n)        否
 * 原地哈希法  O(n)      O(1)        是
 * 负数标记法  O(n)      O(1)        是
 */
class Solution {
 public:
  int findRepeatNumber(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      int index = nums[i] == -n ? 0 : abs(nums[i]);
      if (nums[index] < 0) {
        return index;
      } else {
        nums[index] *= -1;
        if (nums[index] == 0) {
          nums[index] = n * -1;
        }
      }
    }
    return -1;
  }
};