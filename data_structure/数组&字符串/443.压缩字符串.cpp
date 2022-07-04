/**
 * https://leetcode.cn/problems/string-compression/
 * 
 */
class Solution {
 public:
  int compress(vector<char>& chars) {
    int n = chars.size();
    int l = 0, r = 1;
    int cnt = 1;
    while (r <= n) {
      if (r == n || chars[r - 1] != chars[r]) { // 遇到不同的，输出一次
        chars[l++] = chars[r - 1];
        if (cnt > 1) {
          string cur = to_string(cnt);
          for (int i = 0; i < cur.size(); i++) {
            chars[l++] = cur[i];
          }
        }
        cnt = 1;
      } else {
        cnt++;
      }
      r++;
    }
    return l;
  }
};