/**
 * https://leetcode.cn/problems/remove-invalid-parentheses/
 * 这道题说的是删除最少的括号，每次只删除一个括号，然后观察被删除一个括号后是否合法，
 * 如果已经合法了，就不用继续删除了啊。因此我们并不需要将遍历进行到底，而是层层深入，
 * 一旦达到需求，就不再深入了。
 * 
 */
class Solution {
 public:
  vector<string> removeInvalidParentheses(string s) {
    vector<string> res;

    bool got = false; // 是否找到合法
    unordered_set<string> level; // 用 set 避免重复
    level.insert(s);
    while (!level.empty()) {
      unordered_set<string> next_level; // 下一层遍历的字符串
      for (auto& ss : level) {
        if (isVaild(ss)) { // 找到一个合法的，标记在本层退出
          got = true;
          res.push_back(ss);
        }
        if (got) continue;
        // 尝试删除当前字符串中的每一个括号，并在下一层中判断合法性
        for (int i = 0; i < ss.size(); i++) {
          if (ss[i] == '(' || ss[i] == ')') // 如果当前位置是括号，尝试删除
            next_level.insert(ss.substr(0, i) + ss.substr(i + 1));
        }
      }
      level = std::move(next_level); // 更新下次判断的层级
    }
    return res;
  }
  bool isVaild(const string& s) {
    int cnt = 0; // 只有小括号，可以用计数法判断合法性，右括号数不能大于左括号数
    for (auto c : s) {
      if (c == '(')
        cnt++;
      else if (c == ')') {
        cnt--;
        if (cnt < 0) return false;
      }
    }
    return cnt == 0;
  };
};