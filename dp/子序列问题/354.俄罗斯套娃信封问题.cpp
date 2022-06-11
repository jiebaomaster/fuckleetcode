/**
 * https://leetcode-cn.com/problems/russian-doll-envelopes/
 * https://labuladong.gitbook.io/algo/mu-lu-ye-2/mu-lu-ye-1/xin-feng-qian-tao-wen-ti
 * 先对宽度 w 进行升序排序，如果遇到 w 相同的情况，则按照高度 h 降序排序。
 * 之后把所有的 h 作为一个数组，在这个数组上计算最长递增子序列的长度就是答案。
 * 排序后等于把在二维(长、宽)上的最长递增子序列问题转换成一维(宽)上的最长递增
 * 子序列的查找, 因为长度已经满足递增, 只需要在宽度上也递增即可
 * 1. 排序后序列中宽度是升序的，保证了依次取得的宽度总是满足要求的；
 * 2. 求高度的递增子序列，又保证了高度是满足要求的；
 * 3. 宽度相同时高度是降序的，要保证子序列高度的升序，相同宽度下只能被取到一个，则不会出现宽度的冲突
 */
class Solution {
 public:
  int maxEnvelopes(vector<vector<int>>& envelopes) {
    auto cmp = [](const vector<int>& pre, const vector<int>& cur) {
      if (pre[0] != cur[0]) {  // 宽度升序
        return pre[0] < cur[0];
      } else {  // 高度降序，保证相同宽度的只能被取到一个
        return pre[1] > cur[1];
      }
    };
    // 先排序
    sort(envelopes.begin(), envelopes.end(), cmp);
    
    int res = 1;
    // 按高度，求最长递增子序列长度
    vector<int> dp(envelopes.size(), 1);
    for (int i = 1; i < dp.size(); i++) {
      for (int j = 0; j < i; j++) {
        dp[i] = max(dp[i], envelopes[i][1] > envelopes[j][1] ? dp[j] + 1 : 1);
      }
      res = max(res, dp[i]);
    }

    return res;
  }
};

/**
 * 方法二：用二分法优化求最长递增子序列部分
 */
class Solution {
 public:
  int maxEnvelopes(vector<vector<int>>& envelopes) {
    sort(envelopes.begin(), envelopes.end(), [](auto& lhs, auto& rhs) {
      if (lhs[0] == rhs[0])
        return lhs[1] > rhs[1];
      else
        return lhs[0] < rhs[0];
    });

    vector<int> tail(envelopes.size());
    int res = 0;
    for (auto& n : envelopes) {
      int l = 0, r = res;
      while (l < r) {
        int mid = l + (r - l) / 2;
        if (tail[mid] < n[1])
          l = mid + 1;
        else
          r = mid;
      }
      tail[l] = n[1];
      if (l == res) res++;
    }
    return res;
  }
};