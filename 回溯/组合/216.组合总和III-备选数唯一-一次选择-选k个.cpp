/**
 * https://leetcode-cn.com/problems/combination-sum-iii/
 * 1. 基于 track 位置的回溯法
 */
class Solution {
 public:
  vector<vector<int>> res;  // 结果集
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> track;
    backtracking(0, n, 1, k, track);
    return res;
  };
  // 考虑 track[d] 的所有选择，d 为当前递归层数
  void backtracking(int cur, int target, int index, int k, vector<int>& track) {
    if (track.size() == k) { // track.size() 也可以用一个函数参数记录当前已选的个数，性能更好一点
      if (cur == target) res.push_back(track);
      return;
    }

    for (int i = index; i <= 9; i++) {
      if (cur + i > target)  // 剪枝，组合总和不能大于要求值
        break;

      track.push_back(i);
      cur += i;
      // 考虑 track[d+1] 的所有选择 [i...9]
      backtracking(cur, target, i + 1, k, track);
      cur -= i;
      track.pop_back();
    }
  };
};

/**
 * 2. 基于选择集的 dfs
 */
class Solution {
 public:
  vector<vector<int>> res;  // 结果集
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> track;
    dfs(track, 1, k, n, 0);
    return res;
  };

  void dfs(vector<int>& track, int index, int k, int n, int cur) {
    if (index > 9) { // 1~9 中的每一个数都考虑过了
      if (track.size() == k && cur == n) // 满足题目要求
        res.push_back(track);
      return;
    }

    if (cur + index <= n && track.size() < k) { // 剪枝
      track.push_back(index);
      cur += index;
      // 选择 index
      dfs(track, index + 1, k, n, cur);
      cur -= index;
      track.pop_back();
    }

    // 不选择 index，考虑 index+1
    dfs(track, index + 1, k, n, cur);
  }
}