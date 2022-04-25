/**
 * https://leetcode-cn.com/problems/remove-all-adjacent-duplicates-in-string/
 * 方法一：栈，判断栈顶元素和入栈元素是否相等
 */
class Solution {
 public:
  string removeDuplicates(string s) {
    string res;
    for (char c : s) {
      if (!res.empty() && res.back() == c) {
        res.pop_back();
      } else {
        res.push_back(c);
      }
    }
    return res;
  }
};

/**
 * 方法二：双指针模拟本地栈
 */
class Solution1 {
 public:
  string removeDuplicates(string s) {
    int l = 0, // 可以放置元素的位置
        r = 0;
    while (r < s.size()) {
      s[l] = s[r++];
      if (l > 0 && s[l] == s[l - 1]) // 相等时，l回退
        l--;
      else
        l++;
    }
    s.resize(l);
    return s;
  }
};