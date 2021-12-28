/**
 * https://leetcode-cn.com/problems/combinations/
 * 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合

 * 1. 基于 track 位置的回溯法
 */
class Solution {
 public:
  vector<vector<int>> res; // 结果集
  vector<vector<int>> combine(int n, int k) {
    vector<int> track;
    backtracking(track, 1, n, k);
    return res;
  }

  // 考虑 track[d] 的所有选择，d 为当前递归层数
  void backtracking(vector<int> &track, int start, int n, int k) {
    if (track.size() == k) {
      res.push_back(track);
      return;
    }

    for (int i = start; i <= n; i++) { // 遍历位置 start 的所有选择
      track.push_back(i);
      // 考虑 track[d+1] 的所有选择 [i+1...n]
      backtracking(track, i + 1, n, k);
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
  vector<vector<int>> combine(int n, int k) {
    vector<int> track;
    dfs(track, 1, n, k);
    return res;
  }

  void dfs(vector<int> &track, int start, int n, int k) {
    if (start > n) { // n 中的每一个数都考虑过了
      if (track.size() == k) // 路径中有 k 个元素
        res.push_back(track);
      return;
    }

    if (track.size() < k) { // 剪枝，tracking 中的元素个数不能大于 k
      track.push_back(start);
      dfs(track, start + 1, n, k); // 选择 start，考虑 start+1
      track.pop_back();
    }

    dfs(track, start + 1, n, k); // 不选择 start，考虑 start+1
  }
};