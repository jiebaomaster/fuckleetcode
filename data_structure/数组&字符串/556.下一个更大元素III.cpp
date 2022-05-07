/**
 * https://leetcode-cn.com/problems/next-greater-element-iii/
 * https://leetcode-cn.com/problems/next-greater-element-iii/solution/tan-tan-zhu-code-c-apizhan-shen-by-tanyf-iirc/
 * 这一题本质上是求下一个排列，参考第 31 题
 * 1. 寻觅（从后往前找到第一个不满足递减的数）
 *    1 2 5 【6】 7 6 5 4
 * 2. 排序（将该数后面的数字排序以保证更小）
 *    1 2 5 6 【4 5 6 7】
 * 3. 交换（找到第一个大于该数的数字下标，并交换位置）
 *    1 2 5 【7】 4 5 6 【6】
 */
class Solution {
 public:
  int nextGreaterElement(int n) {
    string ns = to_string(n);
    int len = ns.size();
    if (len == 1) return -1;
    for (int i = len - 2; i >= 0; i--) {
      if (ns[i] < ns[i + 1]) { // 寻找非递减数
        // 排序
        sort(ns.begin() + i + 1, ns.end());
        // 查找第一个更大数
        auto bigger = upper_bound(ns.begin() + i + 1, ns.end(), ns[i]);
        // 和第一个更大数交换
        swap(ns[i], ns[distance(ns.begin(), bigger)]);
        // 返回
        long t = atol(ns.c_str());
        if (t > INT_MAX) // 防止越界
          return -1;
        else
          return t;
      }
    }

    return -1;
  }
};