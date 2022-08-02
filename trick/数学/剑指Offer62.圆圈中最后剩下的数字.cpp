/**
 * https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/
 * https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/solution/jian-zhi-offer-62-yuan-quan-zhong-zui-ho-dcow/
 * 约瑟夫环问题，直接模拟会超时，需要找删除前后，数字下标的关系
 * 一个数字 k 被删除后，k 之后的数字都移动到数组最前面，准备下一次删除
 * f(n,m) 表示在长度为 n 的数组中环形删除第 m 个数字后，最后剩余的元素 k 的下标
 * 则无论 m 是多少，最终留下的数字下标一定 0，即 f(1, m) = 0
 * 
 * 可由删除后的数字下标，求得删除前的下标
 * 删除前下标为 f(n,m) = (f(n-1,m)+m) % n
 */
class Solution {
 public:
  int lastRemaining(int n, int m) {
    int s = 0;
    for (int i = 2; i <= n; i++) {
      s = (s + m) % i;
    }
    return s;
  }
};