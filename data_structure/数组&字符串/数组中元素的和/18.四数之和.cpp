/**
 * https://leetcode-cn.com/problems/4sum/
 * 和三数之和的思路一致，排序双指针，只是外边再套了一层循环
 * 注意再套一层循环也是要去重的
 */
class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      // 去重
      if (i > 0 && nums[i] == nums[i - 1]) continue;
      for (int j = i + 1; j < n; j++) {
        // 注意这里的去重，类似回溯求组合中的去重
        if (j > i + 1 && nums[j] == nums[j - 1]) continue;

        int l = j + 1;
        int r = n - 1;
        while (l < r) {
          // 用 long 防止越界
          long t =
              (long)nums[i] + (long)nums[j] + (long)nums[l] + (long)nums[r];
          if (t < target) {
            l++;
            while (l < r && nums[l] == nums[l - 1]) l++;
          } else if (t > target) {
            r--;
            while (l < r && nums[r] == nums[r + 1]) r--;
          } else {
            res.push_back({nums[i], nums[j], nums[l], nums[r]});
            l++;
            while (l < r && nums[l] == nums[l - 1]) l++;
            r--;
            while (l < r && nums[r] == nums[r + 1]) r--;
          }
        }
      }
    }
    return res;
  }
};