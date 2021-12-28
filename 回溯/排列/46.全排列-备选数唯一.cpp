/**
 * https://leetcode-cn.com/problems/permutations/
 * https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/solution/c-zong-jie-liao-hui-su-wen-ti-lei-xing-dai-ni-ga-4/
 * https://labuladong.gitee.io/algo/4/29/104/
 * 1. 基于数字是否已使用的回溯
 */
class Solution {
 public:
  vector<vector<int>> res; // 结果集

  vector<vector<int>> permute(vector<int>& nums) {
    vector<int> track; // 路径
    // 记录 nums[i] 有没有出现在路径中，每个 nums[i] 只能使用一次
    vector<bool> used(nums.size(), false);

    backtracking(track, nums, used);
    return res;
  };

  void backtracking(vector<int> &track, vector<int>& nums, vector<bool>& used) {
    if (track.size() == nums.size()) { // 满足结束条件
      res.push_back(track);
      return;
    }

    // 任意点都可能出现在当前位置，只要其不曾在路径中出现过
    for (int i = 0; i < nums.size(); i++) {
      if (used[i]) // nums[i] 已在路径中，跳过
        continue;

      track.push_back(nums[i]); // 做选择
      used[i] = true;
      backtracking(track, nums, used);
      used[i] = false;
      track.pop_back(); // 撤销选择
    }
  }
};

/**
 * 2. 基于交换的回溯
 * 要求 nums[i...len-1] 的全排列，如果位置 i 处的元素确定，只需要求 nums[i+1...len-1] 的全排列
 * nums[i] 之后的任意元素都可以出现在位置 i 处
 */
class Solution1 {
 public:
  vector<vector<int>> res; // 结果集

  vector<vector<int>> permute(vector<int>& nums) {
    back_tracking(nums, 0);
    return res;
  };

  /**
   * @brief 排列 nums[i...len-1]
   * @param i 当前判断的位置
   */
  void back_tracking(vector<int>& nums, int i) {
    if (i == nums.size()) {
      res.push_back(nums);
      return;
    }

    // 要求 nums[i...len-1] 的全排列，如果位置 i 处的元素确定，只需要求 nums[i+1...len-1] 的全排列
    // nums[i] 之后的任意元素都可以出现在位置 i 处，遍历 nums[i] 之后的所有元素
    for (int j = i; j < nums.size(); j++) {
      swap(nums[i], nums[j]); // nums[j] 作为位置 i 处的元素
      back_tracking(nums, i + 1); // 排列 nums[i+1...len-1]
      swap(nums[i], nums[j]); // 回溯
    }
  }
};