/**
 * https://leetcode-cn.com/problems/3sum/
 * 在数组中找组合为 0 的三元组
 * 第一眼看起来是个组合总和问题，但是回溯法会超时。可以先固定选择 i，
 * 再在子数组 [i+1, n] 中用双指针法找 nums[l]+nums[r]=-nums[i] 的 [l,r]
 */
class Solution {
 public:
  vector<vector<int>> res;
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n; i++) { // 以每个 i 作为三元组中第一个元素
      if (i > 0 && nums[i] == nums[i - 1]) // 重复的 i 去重
        continue;

      int l = i + 1, r = n - 1;
      while (l < r) { // 在子数组[i+1, n]中寻找另外两个
        int tmp = nums[i] + nums[l] + nums[r];
        if (tmp == 0) { // 找到一个符合条件的组合
          res.push_back({nums[i], nums[l], nums[r]});
          // 找到答案时，双指针同时收缩
          l++;
          r--;
          // 跳过重复的 l 和 r
          while(l < r && nums[l] == nums[l-1]) l++;
          while(l < r && nums[r] == nums[r+1]) r--;
        } else if (tmp > 0) {
          r--;
        } else {
          l++;
        }
      }
    }

    return res;
  }
};