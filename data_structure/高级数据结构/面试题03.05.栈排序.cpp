/**
 * https://leetcode.cn/problems/sort-of-stacks-lcci/
 * 设计一个栈顶到栈底从小到大排序的栈
 * 增量思考，原先的栈中元素是满足排序要求的，现在要压入一个新的元素，并保持排序性
 */
class SortedStack {
 public:
  stack<int> st;
  stack<int> buf;
  SortedStack() {}

  void push(int val) {
    // 弹出，直到找到比 val 大的
    while (!st.empty() && st.top() < val) {
      buf.push(st.top());
      st.pop();
    }
    // 压入 val
    st.push(val);
    // 压回转移出去的元素
    while (!buf.empty()) {
      st.push(buf.top());
      buf.pop();
    }
  }

  void pop() {
    if (!st.empty()) st.pop();
  }

  int peek() { return st.empty() ? -1 : st.top(); }

  bool isEmpty() { return st.empty(); }
};