/**
 * https://leetcode-cn.com/problems/permutations-ii/submissions/
 * https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/solution/c-zong-jie-liao-hui-su-wen-ti-lei-xing-dai-ni-ga-4/
 * 求排列思路参考 46 题解法 1，去重思路参考 90 题，画出递归树
 *       [1,2,2]        求排列时产生的递归树
 *      /   |    \
 *     1    2    *2
 *    /\    /\    /\
 *   2 *2  1  2 *1  *2
 *   |  |  |  |  |  |
 *   2 *2  2  1 *2  *1
 * 
 * 观察递归选择树，带*号的是重复子集，可知重复的选择发生在相邻的重复元素分支上。
 * 则在选择每一步的元素时，应该去除选择列表中，与上一个数重复的那个数，
 */
class Solution {
 public:
  vector<vector<int>> res; // 结果集

  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<int> track; // 路径
    // 记录 nums[i] 有没有出现在路径中，每个 nums[i] 只能使用一次
    vector<bool> used(nums.size(), false);
    // 给数组排序，使重复的元素排列在一起
    sort(nums.begin(), nums.end());
    backtracking(track, nums, used);
    return res;
  };

  void backtracking(vector<int> &track, vector<int>& nums, vector<bool>& used) {
    if (track.size() == nums.size()) { // 满足结束条件
      res.push_back(track);
      return;
    }

    // 任意点都可能出现在当前位置，只要其不曾在路径中出现过，且不重复
    for (int i = 0; i < nums.size(); i++) {
      if (used[i]) // nums[i] 已在路径中，跳过
        continue;

      /**
       * 1. nums[i] == nums[i - 1] 排除了重复的选项
       * 2. !used[i-1] 保证了下一轮递归层级中出现的重复元素可以被子集选中，
       *    但本轮选择中出现的重复元素不可以被子集选中。例如 [1 2 2] 中
       *    第二个 2 不应该在选择第一个位置的元素时被选中，但是应该在第一个
       *    元素是 2 时，可以被选为第二个元素，即子集 [2 2]
       */
      if (i > 0 && nums[i] == nums[i-1] && !used[i-1])
        continue;

      track.push_back(nums[i]); // 做选择
      used[i] = true;
      backtracking(track, nums, used);
      used[i] = false;
      track.pop_back(); // 撤销选择
    }
  }
};