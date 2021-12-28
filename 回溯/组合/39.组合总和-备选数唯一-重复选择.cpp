/**
 * https://leetcode-cn.com/problems/combination-sum/
 * 从 candidates 中选择任意个数，他们的总和为 target
 * 
 * 1. 基于 track 位置的回溯法
 */
class Solution {
 public:
  vector<vector<int>> res; // 结果集
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> track;
    // 从小到大排序，方便后续剪枝
    sort(candidates.begin(), candidates.end());
    backtracking(0, target, 0, candidates, track);
    return res;
  };

  // 考虑 track[d] 的所有选择，d 为当前递归层数
  void backtracking(int cur, int target, int index, vector<int>& candidates,
                    vector<int>& track) {
    if (cur == target) {
      res.push_back(track);
      return;
    }

    for (int i = index; i < candidates.size(); i++) {
      if (cur + candidates[i] > target)  // 剪枝，组合总和不能大于要求值
        break;

      track.push_back(candidates[i]);
      cur += candidates[i];
      // 考虑 track[d+1] 的所有选择 candidates[i...]
      backtracking(cur, target, i, candidates, track); 
      cur -= candidates[i];
      track.pop_back();
    }
  }
};

/**
 * 2. 基于选择集的 dfs
 */
class Solution1 {
 public:
  vector<vector<int>> res; // 结果集
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> track;
    dfs(0, target, 0, candidates, track);
    return res;
  };

  void dfs(int cur, int target, int index, vector<int>& candidates,
           vector<int>& track) {
    if (index == candidates.size()) { // n 中的每一个数都考虑过了
      if (cur == target) // 满足题目要求
        res.push_back(track);
      return;
    }

    if (cur < target) { // 剪枝，组合总和不能大于要求值
      track.push_back(candidates[index]);
      cur += candidates[index];
      // 选择 start，因为元素可以重复选，仍然考虑 start
      dfs(cur, target, index, candidates, track);
      cur -= candidates[index];
      track.pop_back();
    }

    // 不选择 start，考虑 start+1
    dfs(cur, target, index + 1, candidates, track);
  }
};