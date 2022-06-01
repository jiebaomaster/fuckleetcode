/**
 * https://leetcode.cn/problems/can-you-eat-your-favorite-candy-on-your-favorite-day/
 * https://leetcode.cn/problems/can-you-eat-your-favorite-candy-on-your-favorite-day/solution/gong-shui-san-xie-qian-zhui-he-qiu-jie-c-b38y/
 * 每天的吃糖数量为 [1, queries[i][2]]，因此我们可以计算出「最早/最晚」吃到第 
 * queries[i][0] 类糖果的时间，然后判断 queries[i][1] 是否落在范围内，
 * 若落在范围内返回则有 ans[i] 为 True，否则为 False。
 */
class Solution {
 public:
  vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
    int n = candiesCount.size();
    vector<long long> prefix(n + 1);
    for (int i = 1; i <= n; i++) {
      prefix[i] = prefix[i - 1] + candiesCount[i - 1];
    }

    vector<bool> res(queries.size());
    for (int i = 0; i < queries.size(); i++) {
      auto& q = queries[i];
      // 最少每天吃 1 颗，q[0] 类最晚可以吃到 prefix[q[0] + 1] 天
      // 最多每天吃 q[2] 颗，q[0] 类最早在 (prefix[q[0]] / q[2]) + 1 天吃到
      if (prefix[q[0] + 1] >= q[1] + 1 &&
          prefix[q[0]] < (long long)(q[1] + 1) * q[2])
        res[i] = true;
    }
    return res;
  }
};