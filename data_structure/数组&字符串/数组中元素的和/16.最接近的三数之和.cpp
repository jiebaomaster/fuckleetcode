/**
 * https://leetcode-cn.com/problems/3sum-closest/
 * 参考第 15 题三数之和
 */
class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    int res = nums[0] + nums[1] + nums[2];
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
      if (i != 0 && nums[i] == nums[i - 1]) continue;
      int l = i + 1;
      int r = nums.size() - 1;
      while (l < r) {
        int t = nums[l] + nums[r] + nums[i];
        if (t > target) {
          while (l < r && nums[r] == nums[r - 1]) r--;
          r--;
        } else if (t < target) {
          while (l < r && nums[l] == nums[l + 1]) l++;
          l++;
        } else // 遇到有相等的直接返回
          return target;

        // 更新最接近的三数之和
        if (abs(target - t) < abs(target - res)) {
          res = t;
        }
      }
    }
    return res;
  }
};