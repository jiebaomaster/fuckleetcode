/**
 * https://leetcode.cn/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/
 * 模拟出栈
 * 
 * 一组合法的入栈序列和出栈序列对应着一个二叉树的前序和中序，也可以通过判断是否能够组成一个二叉树判断
 */
class Solution {
 public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> s;
    int n = pushed.size();
    for (int i = 0, j = 0; i < n; i++) { // 遍历出栈顺序
      while (s.empty() || s.top() != popped[i]) { // 入栈，直到可以出栈
        if (j >= n) return false; // 入不了栈了，返回 false
        s.push(pushed[j++]);
      }
      s.pop(); // 出栈一次
    }
    return true;
  }
};