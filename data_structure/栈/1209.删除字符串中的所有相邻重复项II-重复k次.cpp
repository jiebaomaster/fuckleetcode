/**
 * https://leetcode-cn.com/problems/remove-all-adjacent-duplicates-in-string-ii/
 * 方法一：双指针模拟，类似 1047 题，每次需要向回看 k 个，会超时
 */
class Solution {
 public:
  string removeDuplicates(string s, int k) {
    int l = 0, r = 0;
    while (r < s.size()) {
      s[l] = s[r++];
      int i = l - 1;
      while (i >= 0 && s[l] == s[i]) {  // 向回看
        if (l - i == k - 1) { // 重复达到 k 个，回退
          l -= k;
          break;
        }
        i--;
      }
      l++;
    }
    s.resize(l);
    return s;
  }
};

/**
 * 方法二：双栈法，结果栈和计数栈
 */
class Solution1 {
 public:
  string removeDuplicates(string s, int k) {
    vector<int> times; // 记录前一个数出现的次数
    string res;
    for (char c : s) {
      if (times.empty()) {
        times.push_back(1);
        res.push_back(c);
      } else if (res.back() == c) {
        // 当前数与前一个数相同，更新出现次数
        times.back()++;
        res.push_back(c);
        // 如果出现次数达标，将前一个数退出结果栈和计数栈
        if (times.back() == k) {
          times.pop_back();
          for (int i = k; i > 0; i--) // 结果栈回退 k 个
            res.pop_back();
        }
      } else {
        // 当前数与前一个数不同，计数栈压入新的计数 1 
        times.push_back(1);
        res.push_back(c);
      }
    }
    return res;
  }
};
