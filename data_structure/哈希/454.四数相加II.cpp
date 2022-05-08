/**
 * https://leetcode-cn.com/problems/4sum-ii/
 * 这一题要在4个单独的数组中分别找一个数，而 18 题是在一个数组中找 4 个数
 * 且本题不需要考虑去重
 * 类似两数之和的 hash 解法
 */
class Solution {
 public:
  int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                   vector<int>& nums4) {
    unordered_map<int, int> times;
    for (auto n1 : nums1) {
      for (auto n2 : nums2) {
        times[n1 + n2]++;
      }
    }

    int res = 0;
    for (auto n3 : nums3) {
      for (auto n4 : nums4) {
        if (times.find(0 - n3 - n4) != times.end()) {
          res += times[0 - n3 - n4];
        }
      }
    }
    return res;
  }
};