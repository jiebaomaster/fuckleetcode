/**
 * https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/
 */
class CQueue {
 public:
  stack<int> s1;
  stack<int> s2;
  CQueue() {}

  void appendTail(int value) { s1.push(value); }

  int deleteHead() {
    if (s1.empty() && s2.empty()) return -1;
    if (s2.empty()) {
      while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
      }
    }
    int tmp = s2.top();
    s2.pop();
    return tmp;
  }
};
