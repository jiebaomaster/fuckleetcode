
/**
 * https://leetcode-cn.com/problems/remove-duplicate-letters/
 * https://leetcode-cn.com/problems/remove-duplicate-letters/solution/you-qian-ru-shen-dan-diao-zhan-si-lu-qu-chu-zhong-/
 * https://leetcode-cn.com/problems/remove-duplicate-letters/solution/yi-zhao-chi-bian-li-kou-si-dao-ti-ma-ma-zai-ye-b-4/
 * 
 * 高级字符串去重，求一个字典序最小的不重复子串，保证顺序可以联想到单调栈，
 * 字典序最小即单调递增栈，栈顶元素只有在其字符后面还存在时才能出栈
 * 附加出栈条件保证每个字符都只出现一次
 */
class Solution {
 public:
  string removeDuplicateLetters(string s) {
    stack<char> stack;     // 单调栈保证字典序最小
    int times[256] = {0};  // 记录在当前位置之后，每个字母还会出现几次
    bool inStack[256] = {0}; // 记录字母是否出现在栈中

    for (auto c : s) { // 统计每个字母出现的次数
      times[c]++;
      inStack[c] = false;
    }

    for (auto c : s) {
      times[c]--; // 更新字母还会出现的次数

      if (inStack[c]) continue; // 去重，已经在栈中的元素不重复入栈

      // 对于当前元素 c，为了保持字典序最小，如果 c 小于栈顶元素，有可能需要抛弃栈顶元素
      // 但是栈顶元素如果在这之后都不会出现了，就不能抛弃栈顶元素，否则就会丢失当前栈顶元素
      while (!stack.empty() && times[stack.top()] && c < stack.top()) {
        inStack[stack.top()] = false;
        stack.pop();
      }
      stack.push(c);
      inStack[c] = true; // 记录字母 c 已经在栈中
    }

    string res;
    while (!stack.empty()) {
      res = stack.top() + res; // 栈中的元素要逆序拼接
      stack.pop();
    }
    return res;
  }
};