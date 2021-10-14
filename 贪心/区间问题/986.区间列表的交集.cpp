/**
 * https://leetcode-cn.com/problems/interval-list-intersections/
 * https://mp.weixin.qq.com/s/Eb6ewVajH56cUlY9LetRJw
 */
class Solution {
 public:
  vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                           vector<vector<int>>& secondList) {
    vector<vector<int>> res; // 结果集
    int i = 0, j = 0; // 类似合并有序数列，双指针遍历分别两个区间
    while (i < firstList.size() && j < secondList.size()) {
      /**
       * 只有下列两种情况是没有交集的
       * firstList: [---]          |         [---]
       * secondList:      [----]   | [----]
       */
      if (!(firstList[i][1] < secondList[j][0] ||
            firstList[i][0] > secondList[j][1]))
        /**
         * 有交集只有下面4种情况，则交集为 [max{a1,b1}, min{a2,b2}]
         * 1:         2:
         * [----]     [-------]
         *    [----]     [---]
         * 3:         4:
         *    [----]     [---]
         * [----]     [-------]
         */
        res.push_back({max(firstList[i][0], secondList[j][0]),
                       min(firstList[i][1], secondList[j][1])});

      // 移动遍历指针，终点较大的区间还有可能产生交集，故移动终点较小的
      if (firstList[i][1] > secondList[j][1])
        j++;
      else
        i++;
    }
    return res;
  }
};