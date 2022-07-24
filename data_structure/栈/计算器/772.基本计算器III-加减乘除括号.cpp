/**
 * https://leetcode-cn.com/problems/basic-calculator-iii/
 * https://leetcode-cn.com/problems/basic-calculator/solution/shuang-zhan-jie-jue-tong-yong-biao-da-sh-olym/
 * 计算器的通用解决方案，双栈法
 */
class Solution {
 public:
  unordered_map<int, int> ops_rank = { // 运算符号的优先级
      {'#', 0}, // 
      {'+', 1},
      {'-', 1},
      {'*', 2},
      {'/', 2},
  };
  // 在 s 的最后压入特殊运算符 #，使得 ops 中所有符号都计算完
  s.push_back('#');
  stack<int> ops; // 符号栈
  stack<int> nums; // 运算数栈
  int calculate(string s) {
    nums.push(0); // 处理第一个操作数是负数的情况
    for (int i = 0; i < s.size(); i++) {
      char c = s[i];
      if (c == ' ')
        continue;
      else if (isdigit(c)) { // 数字，拼接值，入操作数栈
        int num = c - '0';
        while (isdigit(s[i + 1]))
          num = num * 10 + (s[++i] - '0');
        nums.push(num);
      } else if (c == '(') {
        ops.push('(');
      } else if (c == ')') {
        // 右括号，完成左括号前的所有计算
        while (ops.top() != '(') eval();
        // 左括号出栈
        ops.pop();
      } else {  // 运算符
        // 如果当前操作符的优先级 与 栈顶操作符相比 更低或相等
        // 进行一次计算，保证优先级高的操作符先计算，相同优先级的从左向右计算
        while (!ops.empty() && ops_rank[ops.top()] >= ops_rank[c]) eval();
        ops.push(c);
      }
    }
    return nums.top();
  }

  // 取栈顶的两个数字和栈顶操作符进行一次计算，计算结果放回操作数栈
  void eval() {
    int a = nums.top();
    nums.pop();  // 右操作数
    int b = nums.top();
    nums.pop();  // 左操作数
    int op = ops.top();
    ops.pop();
    int res;
    // 计算
    switch (op) {
      case '+':
        res = a + b;
        break;
      case '-':
        res = b - a;
        break;
      case '*':
        res = a * b;
        break;
      case '/':
        res = b / a;
        break;
      default:
        res = -1;
    }
    // 计算结果放回操作数栈
    nums.push(res);
  }
};