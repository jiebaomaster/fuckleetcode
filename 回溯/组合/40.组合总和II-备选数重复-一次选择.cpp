/**
 * https://leetcode-cn.com/problems/combination-sum-ii/
 * 
 * 备选数重复的情况，去重思路参考 90 题
 */
class Solution {
 public:
  vector<vector<int>> res;
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<int> tracking;
    sort(candidates.begin(), candidates.end());

    backtracking(0, candidates, 0, target, tracking);
    return res;
  };

  void backtracking(int index, vector<int>& candidates, int cur, int target,
                    vector<int>& tracking) {
    if (cur == target) {
      res.push_back(tracking);
      return;
    }

    for (int i = index; i < candidates.size(); i++) {
      if (index != i && candidates[i] == candidates[i - 1]) // 去重
        continue;

      if (cur + candidates[i] > target) // 剪枝，组合总和不能大于要求值
        break;

      cur += candidates[i];
      tracking.push_back(candidates[i]);
      backtracking(i + 1, candidates, cur, target, tracking);
      tracking.pop_back();
      cur -= candidates[i];
    }
  }
};