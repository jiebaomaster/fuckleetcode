/**
 * https://leetcode.cn/problems/random-pick-with-weight/
 * https://leetcode.cn/problems/random-pick-with-weight/solution/an-quan-zhong-sui-ji-xuan-ze-by-leetcode-h13t/
 *
 * 彩票调度：https://pages.cs.wisc.edu/~remzi/OSTEP/Chinese/09.pdf
 * 工程中，按权重进行负载均衡
 *
 */
class Solution {
 public:
  vector<int> prefix;
  int sum;
  Solution(vector<int>& w) {
    prefix.resize(w.size() + 1);
    // 构建前缀和数组
    for (int i = 1; i <= w.size(); i++) {
      prefix[i] = prefix[i - 1] + w[i - 1];
    }
    sum = prefix.back();
  }

  int pickIndex() {
    int target = rand() % sum;
    int l = 1, r = prefix.size();
    while (l < r) {
      int mid = l + (r - l) / 2;
      // 选择第一个比 target 大的
      if (target >= prefix[mid])
        l = mid + 1;
      else
        r = mid;
    }
    return l - 1;
  }
};