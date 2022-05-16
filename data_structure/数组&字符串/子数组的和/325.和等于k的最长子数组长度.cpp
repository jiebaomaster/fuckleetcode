/**
 * https://leetcode.cn/problems/maximum-size-subarray-sum-equals-k/
 * 类似第 560 题
 * 前缀和+哈希
 */
class Solution {
 public:
  int maxSubArrayLen(vector<int>& nums, int k) {
    int cur = 0;
    // 插入{0,-1}，处理连续数组的起始点在 index == 0 的位置的情况
    unordered_map<int, int> n_index = {{0, -1}};
    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
      cur += nums[i]; // 计算前缀和
      // cur - prefix = k，判断前缀和 cur-k 是否出现过
      if (n_index.count(cur - k)) {
        res = max(res, i - n_index[cur - k]);
      }
      // 添加前缀和 cur 出现的位置
      if (!n_index.count(cur)) {
        n_index[cur] = i;
      }
    }
    return res;
  }
};