/**
 * https://leetcode-cn.com/problems/min-stack/
 * 使用一个辅助的单调栈保存当前元素最小值
 */
class MinStack {
 public:
  stack<int> s;
  stack<int> monos; // 辅助的递减单调栈
  MinStack() { monos.push(INT_MAX); }

  void push(int val) {
    s.push(val);
    if (val <= monos.top()) monos.push(val);
  }

  void pop() {
    int t = s.top();
    s.pop();
    if (t == monos.top()) monos.pop();
  }

  int top() { return s.top(); }

  int getMin() { return monos.top(); }
};