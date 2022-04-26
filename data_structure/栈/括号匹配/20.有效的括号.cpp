/**
 * https://leetcode-cn.com/problems/valid-parentheses/
 * 消消乐，右括号 ")]}" 入栈的时候判断栈顶是否匹配
 */
class Solution {
 public:
  bool isValid(string s) {
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
      if (st.empty()) { // 空栈没有栈顶元素，直接入栈
        st.push(s[i]);
        continue;
      }
      switch (s[i]) {
        case ']':
          if (st.top() == '[') {
            st.pop();
            break;
          } else {
            return false;
          }
          break;
        case ')':
          if (st.top() == '(') {
            st.pop();
            break;
          } else {
            return false;
          }
          break;
        case '}':
          if (st.top() == '{') {
            st.pop();
            break;
          } else {
            return false;
          }
        default:
          st.push(s[i]);
      }
    }
    return st.empty();
  }
};