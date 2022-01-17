/**
 * https://leetcode-cn.com/problems/different-ways-to-add-parentheses/
 * https://labuladong.github.io/algo/4/31/128/
 * 问题：给定一个含有数字和运算符的字符串，为表达式添加括号，改变其运算优先级以求出不同的结果。
 *
 * 对于一个形如 x op y（op 为运算符，x 和 y 为数） 的算式而言，它的结果组合取决于 x 和 y 的
 * 结果组合数，而 x 和 y 又可以写成形如 x op y 的算式。
 * 因此，该问题的子问题就是 x op y 中的 x 和 y：以运算符分隔的左右两侧算式解。
 * 
 * 分治算法三步走：
 *  分解：按运算符分成左右两部分，分别求解
 *  解决：实现一个递归函数，输入算式，返回算式解
 *  合并：根据运算符合并左右两部分的解，得出最终解
 */
class Solution {
 public:
  // 备忘录，可能会出现重复的字符串分割方法，避免重复计算
  unordered_map<string, vector<int>> mem;
  vector<int> diffWaysToCompute(string expression) {
    if (mem.find(expression) != mem.end()) return mem[expression];

    vector<int> res;
    for (int i = 0; i < expression.size(); i++) {
      char ch = expression[i];
      // 扫描算式 input 中的运算符
      if (ch == '+' || ch == '-' || ch == '*') {
        /****** 分 ******/
        // 以运算符为中心，分割成两个字符串，分别递归计算
        auto left = diffWaysToCompute(expression.substr(0, i));
        auto right = diffWaysToCompute(expression.substr(i + 1));
        /****** 治 ******/
        // 通过子问题的结果，合成原问题的结果
        for (int l : left) {
          for (int r : right) {
            if (ch == '+')
              res.push_back(l + r);
            else if (ch == '-')
              res.push_back(l - r);
            else if (ch == '*')
              res.push_back(l * r);
          }
        }
      }
    }
    // base case
    // 如果 res 为空，说明算式是一个数字，没有运算符
    if (res.empty()) res.push_back(stoi(expression));
    // 保存部分结果
    mem[expression] = res;
    return res;
  }
};