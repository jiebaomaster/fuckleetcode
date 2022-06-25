/**
 * https://leetcode.cn/problems/validate-stack-sequences/
 * 同 剑指offer31
 */
class Solution {
 public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> s;
    int i = 0, j = 0;
    while (i < pushed.size()) {
      s.push(pushed[i++]);
      // 入栈一个数，并尽可能出栈
      while (!s.empty() && s.top() == popped[j]) {
        j++;
        s.pop();
      }
    }
    // 最后栈为空则序列合法
    return s.empty();
  }
};