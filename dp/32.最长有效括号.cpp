/**
 * https://leetcode-cn.com/problems/longest-valid-parentheses/
 * 方法一：动态规划 + 栈模拟
 * 设 dp[i] 为以i为结尾的最长有效括号子串长度，
 * 1. 显然结尾必须是 ')' 才是有效的
 * 2. 问题在于寻找当前 ')' 匹配的 '('，括号匹配问题可以用栈解决
 *    设与当前右括号匹配的左括号下标为 left=stack.top()
 *    则 dp[i] = (i - left + 1) + dp[left-1]
 *              当前匹配的括号子串   匹配的左括号之前还有匹配的子串
 */
class Solution {
 public:
  int longestValidParentheses(string s) {
    int res = 0;
    int cur = 0;
    stack<int> st;  // 保存左括号的下标，用于寻找右括号匹配的左括号
    vector<int> dp(s.size(), 0);
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(') {
        st.push(i);
        continue;
      } else {  // )
        if (st.empty()) continue;
        // 当前右括号有匹配的左括号
        int left = st.top();
        st.pop();

        dp[i] = i - left + 1;
        if (left > 0) dp[i] += dp[left - 1];

        res = max(res, dp[i]);
      }
    }
    return res;
  }
};

/**
 * https://leetcode-cn.com/problems/longest-valid-parentheses/solution/zui-chang-you-xiao-gua-hao-by-leetcode-solution/
 * 方法二：dp
 * 可以直接由 dp 判断右括号是否有匹配的左括号，省去栈的空间
 */
class Solution1 {
 public:
  int longestValidParentheses(string s) {
    int res = 0;
    int cur = 0;
    vector<int> dp(s.size(), 0);
    for (int i = 1; i < s.size(); i++) {
      if (s[i] == ')') {        // )
        if (s[i - 1] == '(') {  // 形如 ...()
          dp[i] = 2;
          if (i >= 2)  // 左前部
            dp[i] += dp[i - 2];
        } else {  // 形如 ....))
          // 必须有 ...((---))
          if (dp[i - 1] > 0 && i - dp[i - 1] - 1 >= 0 &&
              s[i - dp[i - 1] - 1] == '(') {  // 前面要有
            dp[i] = dp[i - 1] + 2;
            if (i - dp[i - 1] - 2 > 0)  // 左前部
              dp[i] += dp[i - dp[i - 1] - 2];
          }
        }
        res = max(res, dp[i]);
      }
    }
    return res;
  }
};

/**
 * 方法三：栈模拟
 * 保持栈底元素为当前已经遍历过的元素中「最后一个没有被匹配的右括号的下标」，
 * 这样的做法主要是考虑了边界条件的处理，栈里其他元素维护左括号的下标
 *
 * 其实这一题可以先用栈模拟把所有可以匹配的括号的字符都改成
 * 0，把问题转化为寻找最长的连续 0
 */
class Solution2 {
 public:
  int longestValidParentheses(string s) {
    int res = 0;
    stack<int> st;
    st.push(-1);
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ')') {  // )
        st.pop();
        if (st.empty()) {
          st.push(i);
        } else {
          res = max(res, i - st.top());
        }
      } else {  // (
        st.push(i);
      }
    }
    return res;
  }
};

/**
 * 方法三：括号匹配的性质
 * 用两个计数器分别记录遍历时左括号和右括号的数量
 * 从左向右遍历时，要想存在匹配，左括号数必须大于右括号数，且在相等时必定匹配
 * 这样会漏掉一些情况，比如 "(()"，不会触发相等，只需要再从右向左遍历一次即可
 */
class Solution3 {
 public:
  int longestValidParentheses(string s) {
    int left = 0, right = 0;
    int res = 0;
    // 从左向右遍历
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(')
        left++;
      else
        right++;

      if (left == right) { // 相等时必定匹配
        res = max(res, left + right);
      } else if (left < right) { // 左括号数必须大于右括号数才可能匹配
        left = 0;
        right = 0;
      }
    }
    // 从右向左遍历
    left = 0;
    right = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
      if (s[i] == '(')
        left++;
      else
        right++;

      if (left == right) {
        res = max(res, left + right);
      } else if (left > right) {
        left = 0;
        right = 0;
      }
    }
    return res;
  }
};