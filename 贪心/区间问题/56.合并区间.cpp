/**
 * https://leetcode-cn.com/problems/merge-intervals/
 * https://mp.weixin.qq.com/s/Eb6ewVajH56cUlY9LetRJw
 */
class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(),
         [](vector<int>& a, vector<int>& b) {
           if (a[0] == b[0]) return a[1] > b[1];
           return a[0] < b[0];
         });

    int right = intervals[0][1];
    int left = intervals[0][0];
    vector<vector<int>> res;
    for (int i = 1; i < intervals.size(); i++) {
      /**
       * [---]       产生了一个结果区间
       *       [---]
       *       [---] 不相交，转移
       */
      if (right < intervals[i][0]) {
        res.push_back({left, right}); // 发生转移代表产生了一个结果区间
        left = intervals[i][0];
        right = intervals[i][1];
      } else if (right < intervals[i][1]) {
        /**
         * [----]
         *     [----] 
         * [--------] 交叉，合并
         */
        right = intervals[i][1];
      }
      // 本题区间覆盖时不用处理
    }
    // 最后还有一个有效区间没有加入
    res.push_back({left, right});
    return res;
  }
};