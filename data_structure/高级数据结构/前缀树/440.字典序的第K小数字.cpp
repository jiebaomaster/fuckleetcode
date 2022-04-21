/**
 * https://leetcode-cn.com/problems/k-th-smallest-in-lexicographical-order/
 * https://leetcode-cn.com/problems/k-th-smallest-in-lexicographical-order/solution/ben-ti-shi-shang-zui-wan-zheng-ju-ti-de-shou-mo-sh/
 *
 * 思路参考第 386 题，字典树
 * 但是本题直接前序遍历字典数会超时，需要通过计算每个前缀下所含有的数字个数逐步逼近
 */
class Solution {
 public:
  int res = 0;
  int findKthNumber(int n, int k) {
    long long p = 1;       // 当前位置，当 p==k 时，也就是到了排位第k的数
    long long prefix = 1;  // 当前前缀
    while (p < k) {
      long long cnt = prefixCnt(prefix, n);
      if (p + cnt > k) {  // 第 k 个数在当前前缀下
        prefix *= 10;     // 考虑下一级前缀
        p++;              // 指向下一个位置
      } else {            // 第 k 个数不在当前前缀下
        prefix++;         // 考虑下一个前缀
        p += cnt;         // 指向下一个前缀的位置
      }
    }
    return prefix;
  }
  /**
   * @brief 计算前缀 prefix 下所有子节点数
   *
   * @param prefix 前缀
   * @param limit 上界
   */
  long long prefixCnt(long long prefix, long long limit) {
    long long cnt = 0;
    long long cur = prefix;
    long long next = prefix + 1;  // 下一个前缀
    // 当前的前缀当然不能大于上界
    while (cur <= limit) {
      cnt += min(limit + 1, next) - cur;
      cur *= 10;
      next *= 10;
      /**
       * 如果说刚刚prefix是1，next是2，那么现在分别变成10和20
       * 1为前缀的子节点增加10个，十叉树增加一层, 变成了两层
       *
       * 如果说现在prefix是10，next是20，那么现在分别变成100和200，
       * 1为前缀的子节点增加100个，十叉树又增加了一层，变成了三层
       */
    }
    return cnt;
  }
};