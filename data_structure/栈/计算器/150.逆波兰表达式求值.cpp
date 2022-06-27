/**
 * https://leetcode.cn/problems/evaluate-reverse-polish-notation/
 * 
 */
class Solution {
 public:
  int evalRPN(vector<string>& tokens) {
    if (tokens.size() == 1) return stoi(tokens[0]);
    stack<string> st;
    unordered_set<string> op = {"+", "-", "*", "/"};
    int res;
    for (auto& t : tokens) {
      if (op.find(t) == op.end()) {
        st.push(t);
      } else {
        int rhs = stoi(st.top());
        st.pop();
        int lhs = stoi(st.top());
        st.pop();

        switch (t[0]) {
          case '+':
            res = lhs + rhs;
            break;
          case '-':
            res = lhs - rhs;
            break;
          case '*':
            res = lhs * rhs;
            break;
          case '/':
            res = lhs / rhs;
            break;
          default:
            break;
        }
        st.push(to_string(res));
      }
    }

    return res;
  }
};