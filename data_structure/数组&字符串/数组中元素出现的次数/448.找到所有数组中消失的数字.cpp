/**
 * https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/
 * 
 * 在输入数组中用数字的正负来表示该位置所对应数字是否存在。
 * 遍历输入数组，给对应位置的数字取相反数。
 * 遍历修改后的数组，非负数的位置表示该位置未出现过
 */
class Solution {
 public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> res;

    // 遍历输入数组，给对应位置的数字取相反数
    for (int i = 0; i < nums.size(); i++) {
      int t = abs(nums[i]);
      if (nums[t - 1] > 0) {
        nums[t - 1] *= -1;
      }
    }
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > 0) { // 非负数的位置表示该位置未出现过
        res.push_back(i + 1);
      }
    }
    return res;
  }
};