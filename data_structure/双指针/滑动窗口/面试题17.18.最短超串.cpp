/**
 * https://leetcode.cn/problems/shortest-supersequence-lcci/
 * 类似第 76 题，字符串换成了数组
 */
class Solution {
 public:
  vector<int> shortestSeq(vector<int>& big, vector<int>& small) {
    unordered_map<int, int> wind;
    for (auto n : small) {
      wind[n]++;
    }

    vector<int> res = {0, INT_MAX - 1};
    int l = 0, r = 0;
    int cnt = 0;
    while (r < big.size()) {
      int n = big[r++];
      if (!wind.count(n)) {
        continue;
      }

      wind[n]--;
      if (wind[n] == 0) cnt++;
      while (cnt == wind.size()) {
        if (res[1] - res[0] + 1 > r - l) {
          res = {l, r - 1};
        }
        if (wind.count(big[l])) {
          if (wind[big[l]] == 0) cnt--;
          wind[big[l]]++;
        }
        l++;
      }
    }
    if (res[1] == INT_MAX - 1)
      return {};
    else
      return res;
  }
};