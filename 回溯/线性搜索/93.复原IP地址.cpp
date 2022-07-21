/**
 * https://leetcode-cn.com/problems/restore-ip-addresses/
 * 方法一：基于选择集的 dfs
 */
class Solution {
 public:
  vector<string> res;
  vector<string> restoreIpAddresses(string s) {
    if (s.size() < 4 || s.size() > 12) // ip 地址长度有要求
      return res;
    string tracking;
    dfs(tracking, s, 0, 0);
    return res;
  }
  /**
   * 对每个字符 s[index] 判断是否要在其之后进行分割
   * 
   * @param tracking 当前分割构成的字符串
   * @param s 原字符串
   * @param index 当前判断的字符在原字符串中的索引
   * @param cnt 已进行的分割次数
   */
  void dfs(string &tracking, string &s, int index, int cnt) {
    if (index == s.size()) {
      if (cnt == 3 && check(tracking)) res.push_back(tracking);

      return;
    }

    tracking.push_back(s[index]);

    // 分割 "." 小于 3 次，且 最后一位字符后不能分割
    if (cnt < 3 && index < s.size() - 1) {
      tracking.push_back('.');
      dfs(tracking, s, index + 1, cnt + 1);
      tracking.pop_back();
    }

    dfs(tracking, s, index + 1, cnt);

    tracking.pop_back();
  }
  // 判断分割后的字符串是否合法
  bool check(string &s) {
    int slow = 0;
    for (int fast = 1; fast <= s.size(); fast++) {
      if (fast == s.size() || s[fast] == '.') {
        // 判断 [slow, fast) 是否合法
        if (fast - slow > 1 && s[slow] == '0')  // 前导 0 不合法
          return false;
        if (fast - slow > 3)  // 大于三位数不合法
          return false;
        // 求值
        int i = fast - 1;
        int val = 0;
        int t = 1;
        while (slow <= i) {
          val += t * (s[i--] - '0');
          t *= 10;
        }
        if (val > 255) return false;
        slow = fast + 1;
      }
    }
    return true;
  }
};

/**
 * 方法二：基于 track 位置的回溯法
 */
class Solution {
 public:
  vector<string> res;
  vector<string> restoreIpAddresses(string s) {
    vector<int> track;
    dfs(track, s, 0);
    return res;
  }
  // 遍历所有的分割组合
  void dfs(vector<int> &track, string &s, int index) {
    if (track.size() == 3) { // 分割点最多有三个
      auto r = vaild(s, track);
      if (!r.empty()) res.push_back(r);
      return;
    }

    for (int i = index; i < s.size() - 1; i++) {
      track.push_back(i);
      dfs(track, s, i + 1);
      track.pop_back();
    }
  }

  // 判断分割的 IP 地址是否有效
  string vaild(string &s, vector<int> &track) {
    track.push_back(s.size() - 1); // 压入 n-1 处理最后一段
    string cur;
    int l = 0;
    for (int i = 0; i < 4; i++) {
      int r = track[i] + 1;
      if (!vaildNum(s, l, r - 1)) {
        track.pop_back();
        return "";
      }
      cur += s.substr(l, r - l) + ".";
      l = r;
    }
    cur.pop_back();    // .
    track.pop_back();  // n-1

    return cur;
  }

  // 判断分割出的数字是否有效
  bool vaildNum(string &s, int l, int r) {
    if (r - l + 1 > 3) return false;
    if (r > l && s[l] == '0') return false;
    int cur = 0;
    while (l <= r) {
      cur = cur * 10 + s[l] - '0';
      l++;
    }
    if (cur > 255) return false;
    return true;
  }
};