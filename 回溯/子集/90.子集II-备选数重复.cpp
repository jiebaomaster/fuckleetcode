/**
 * https://leetcode-cn.com/problems/subsets-ii/
 * 
 * 这一题和 78 题的思路大致相同，只是要注意元素的重复产生的重复子集
 *        [1,2,2,3]   选择子集时产生的递归树
 *       /   |  |  \
 *      1    2  *2  3  选择第 1 个数
 *     /| \  |\  \  
 *    2 *2 3 2 3  *3   选择第 2 个数
 *   /| |    ｜
 *  2 3 *3   3         选择第 3 个数
 *  ｜      
 *  3                  选择第 4 个数
 * 观察递归选择树，带*号的是重复子集，可知重复的选择发生在相邻的重复元素分支上。
 * 则在选择每一步的元素时，应该去除选择列表中，与上一个数重复的那个数，
 * 即递归选择树的每一层不能出现重复的选择
 */
class Solution {
 public:
  vector<vector<int>> res;
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<int> track;
    sort(nums.begin(), nums.end()); // 给数组排序，使重复的元素排列在一起
    backtracking(track, 0, nums);
    return res;
  };

  void backtracking(vector<int>& track, int start, vector<int>& nums) {
    // 把递归路径上的所有临时结果都保存到结果集
    res.push_back(track);

    for (int i = start; i < nums.size(); i++) {
      // nums[i] == nums[i - 1] 排除了重复的选项
      // i>start 保证了第一次出现的重复元素可以被子集选中，
      // 例如 [1 2 2] 中第二个 2 不应该在选择第一个位置的元素时被选中，
      // 但是应该在第一个元素是 2 时，可以被选为第二个元素，即子集 [2 2]
      if (i > start && nums[i] == nums[i - 1]) continue;

      track.push_back(nums[i]);
      backtracking(track, i + 1, nums);
      track.pop_back();
    }
  }
};