/**
 * https://leetcode-cn.com/problems/shortest-subarray-with-sum-at-least-k/
 * https://github.com/Shellbye/Shellbye.github.io/issues/41
 * 类似第 209 题，本题需要考虑负数
 *
 * 方法一：前缀和
 * 求子数组的和可以直接想到使用前缀和，然后遍历所有的窗口 [i,j]，求出不小于 k
 * 的窗口长度
 */
class Solution {
 public:
  int shortestSubarray(vector<int>& nums, int k) {
    vector<int> prefix(nums.size());
    prefix[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      prefix[i] = prefix[i - 1] + nums[i];
    }
    int res = INT_MAX;
    int peak = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
      if (peak >= prefix[i]) continue;  // nums[i] 为负数和 0 时不必找，
      peak = prefix[i];
      for (int j = i; j >= 0; j--) {  // 在 0～i 中找 [j~i] >= k
        if (prefix[i] - prefix[j] + nums[j] >= k) {
          res = min(res, i - j + 1);
          break;  // 找到的第一个必是最短的
        }
      }
    }
    return res == INT_MAX ? -1 : res;
  }
};

/**
 * 方法二：单调队列
 */
class Solution {
 public:
  int shortestSubarray(vector<int>& nums, int k) {
    vector<long long> prefix(nums.size() + 1);  // prefix[i] = acc(0, i-1)
    prefix[0] = 0;
    for (int i = 1; i <= nums.size(); i++) {
      prefix[i] = prefix[i - 1] + nums[i - 1];
    }
    int res = INT_MAX;
    deque<int> dq; // 维护单调递增的前缀和，跳过所有负数和 0 
    for (int i = 0; i <= nums.size(); i++) {
      // 维护单调递增的前缀和
      while (!dq.empty() && prefix[dq.back()] >= prefix[i]) {
        dq.pop_back();
      }
      // front～i 是差值最大的
      while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k) {
        res = min(res, i - dq.front());
        // 若 front～i 满足，则 i 扩大后长度必变大，所以 front 出队
        dq.pop_front();
      }

      dq.push_back(i);
    }
    return res == INT_MAX ? -1 : res;
  }
};