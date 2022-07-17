/**
 * https://leetcode-cn.com/problems/valid-parentheses/
 * 消消乐，右括号 ")]}" 入栈的时候判断栈顶是否匹配
 * 如果本题中不要求“左括号必须以正确的顺序闭合”，可以不使用栈，直接用变量记录三个括号的数量
 */
class Solution {
 public:
  bool isValid(string s) {
    stack<char> st;
    for (auto c : s) {
      switch (c) {
        case '(':
        case '[':
        case '{':
          st.push(c);
          break;
        case ')':
          if (st.empty() || st.top() != '(') return false;
          st.pop();
          break;
        case ']':
          if (st.empty() || st.top() != '[') return false;
          st.pop();
          break;
        case '}':
          if (st.empty() || st.top() != '{') return false;
          st.pop();
          break;
      }
    }
    return st.empty();
  }
};