/**
 * https://leetcode.cn/problems/hanota-lcci/
 */
class Solution {
 public:
  void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
    domove(A.size(), A, B, C);
  }
  // 将 A 的上面 n 个盘子通过 B 移动到 C
  void domove(int n, vector<int>& A, vector<int>& B, vector<int>& C) {
    if (n == 1) {
      C.push_back(A.back());
      A.pop_back();
      return;
    }

    // 1. 将 A 的上面 n-1 个盘子通过 C 移动到 B
    domove(n - 1, A, C, B);
    // 此时 A 中只剩一个最大的，其余的 n-1 个在 B 中，C 中为空
    // 2. 移动 A 的最后一个到 C 中
    C.push_back(A.back());
    A.pop_back();
    // 3. 将 B 中的 n-1 个盘子通过 A 移动到 C
    domove(n - 1, B, A, C);
  }
};