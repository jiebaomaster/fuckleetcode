/**
 * https://leetcode-cn.com/problems/basic-calculator/
 * 
 */
class Solution {
 public:
  int calculate(string s) {
    stack<int> stk; // 即时计算结果和括号前的符号
    char sign = 1; // 当前计算结果前的符号
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
      char c = s[i];
      if (isdigit(c)) { // 数字
        // 计算数字值
        int num = 0;
        while (i < s.size() && isdigit(s[i])) {
          num = num * 10 + (s[i++] - '0');
        }
        i--;
        // 添加到结果中，注意符号
        res += sign * num;
      } else if (c == '-') {
        sign = -1;
      } else if (c == '+') {
        sign = 1;
      } else if (c == '(') {
        // 遇到左括号，暂存当前运算结果和括号前的运算符号
        stk.push(res);
        res = 0;
        stk.push(sign);
        sign = 1;
      } else if (c == ')') {
        // 遇到右括号，此时 res 为当前括号内的计算结果
        // 栈顶元素 为当前括号前的运算符号
        // 栈顶元素的下一个 为当前括号前的运算结果
        res *= stk.top(); // 当前括号内的运算结果
        stk.pop();
        res += stk.top(); // 加上括号外的运算结果，即整体运算结果
        stk.pop();
      }
    }
    return res;
  }
};