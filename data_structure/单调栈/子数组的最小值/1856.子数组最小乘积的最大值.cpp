/**
 * https://leetcode.cn/problems/maximum-subarray-min-product/
 * 数组的最小乘积 = 数组的最小值 * 数组之和
 * 求 子数组 的 最小乘积 的最大值
 * 
 * 子数组的最小值可由 单调栈 求得，类似第 84 题
 * 子数组之和可由 前缀和 求得
 */
class Solution {
 public:
  int maxSumMinProduct(vector<int>& nums) {
    int n = nums.size();
    vector<long> prefix(n + 1);
    for (int i = 1; i <= n; i++) {
      prefix[i] = prefix[i - 1] + nums[i - 1];
    }
    nums.push_back(0);
    stack<int> st;
    long res = 0;
    for (int i = 0; i <= n; i++) {
      while (!st.empty() && nums[st.top()] >= nums[i]) {
        int x = nums[st.top()];
        st.pop();
        int l = st.empty() ? 0 : st.top() + 1;
        int r = i - 1;
        // sum[l, r]
        long sum = prefix[r + 1] - prefix[l];
        res = max(res, (long)(x * sum));
      }

      st.push(i);
    }
    return res % 1000000007;
  }
};