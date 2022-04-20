/**
 * https://leetcode-cn.com/problems/basic-calculator-ii/
 * https://leetcode-cn.com/problems/basic-calculator-ii/solution/ji-ben-ji-suan-qi-ii-by-leetcode-solutio-cm28/
 * 
 * 由于乘除优先于加减计算，因此不妨考虑先进行所有乘除运算，并将这些乘除运算后的
 * 整数值放回原表达式的相应位置，则随后整个表达式的值，就等于一系列整数加减后的值。
 * 不带括号的计算器，可以只用一个数据栈，用一个变量存储之前的运算符，
 * 遇到当前运算
 */
class Solution {
 public:
  int calculate(string s) {
    vector<int> stk;
    char sign = '+';
    int num = 0;
    for (int i = 0; i < s.size(); i++) {
      if (isdigit(s[i])) // 当前是数字，继续更新当前数字的值
        num = num * 10 + (s[i] - '0');
      if ((!isdigit(s[i]) && s[i] != ' ') || i == s.size() - 1) {
        // 当前是运算符或者是字符串最后一位，进行计算
        // s[i] 为当前运算符，sign 为前一个运算符
        switch (sign) { // 根据之前的运算符进行计算
          case '+':
            stk.push_back(num);
            break;
          case '-': // 相反数入栈
            stk.push_back(-1 * num);
            break;
          case '*':
            stk.back() *= num;
            break;
          case '/':
            stk.back() /= num;
            break;
        }
        // 重新计算下一个数字
        num = 0;
        // 更新运算符
        sign = s[i];
      }
    }
    return accumulate(stk.begin(), stk.end(), 0);
  }
};