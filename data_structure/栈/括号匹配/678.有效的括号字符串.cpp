/**
 * https://leetcode-cn.com/problems/valid-parenthesis-string/
 *
 * 方法一：双栈法，左括号栈 和 *栈，
 *
 * 两个栈分别将"("和"*"的序号压入栈中，
 * 1. 遍历 s 匹配右括号，匹配 ")" 时优先使用 "("，没有 "(" 时再使用 "*"
 * 2. 右括号匹配完之后，left和star栈可能还存在元素，把star当作右括号与left匹配，
 *    判断此时栈中元素的序号大小，如果left栈中的序号大于star中的则
 *    表明存在 "*(" 这种情况，返回 false
 * 3. 最后 left 必须被匹配完，star 可以留有元素
 */
class Solution {
 public:
  bool checkValidString(string s) {
    stack<int> left;
    stack<int> star;

    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(') {
        left.push(i);
      } else if (s[i] == '*') {
        star.push(i);
      } else {  // )
        if (!left.empty())
          left.pop();
        else if (!star.empty())
          star.pop();
        else
          return false;
      }
    }

    while (!left.empty() && !star.empty()) {
      if (left.top() > star.top()) return false;
      left.pop();
      star.pop();
    }
    return left.empty();
  }
};

/**
 * 方法二：记录当前未匹配左括号数量的范围
 * 这道题是普通括号匹配的变体。回忆一下一般的括号匹配（即没有'*'这个特殊符号），
 * 一般用栈来做，栈用来存储左括号，每当遇到右括号时出栈。实际上，这个栈不是必须的，
 * 只需要用一个变量记录当前未匹配左括号的数量即可。
 * 从这个角度来看，这道题就会简单很多，加入'*'号后，未匹配左括号的数量从一个值变成了
 * 一个范围，所以只需要转变思路，用两个变量来记录这个范围的上下界即可。
 *
 * 任何情况下，未匹配的左括号数量必须非负，因此当最大值变成负数时，说明没有左括号
 * 可以和右括号匹配，返回false。 
 * 遍历结束时，所有的左括号都应和右括号匹配，因此只有当最小值为 0时，才是有效的括号字符串。
 */
class Solution1 {
 public:
  bool checkValidString(string s) {
    int l = 0,  // 左括号数量下界
        h = 0;  // 左括号数量上界
    for (char c : s) {
      if (c == '(') {
        l++;
        h++;
      } else if (c == ')') {
        // 右括号匹配，上下界都需减小
        l = max(l - 1, 0);
        h--;
        // 上界都满足不了匹配了，返回 false
        if (h < 0) return false;
      } else {  // *
        l = max(l - 1, 0); // * 可能作为 ) 与 ( 匹配，下界减小
        h++; // * 可以作为 (，上界增大
      }
    }
    return l == 0;
  }
};