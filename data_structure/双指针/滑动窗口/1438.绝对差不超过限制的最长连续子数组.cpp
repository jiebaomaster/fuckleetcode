/**
 * https://leetcode.cn/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
 * 问题的关键在于维护滑动窗口中元素的最值
 * 
 * 方法一：利用 map 的排序性
 * 时间复杂度 O(nlogn)
 */
class Solution {
 public:
  int longestSubarray(vector<int>& nums, int limit) {
    int l = 0, r = 0;
    // 滑动窗口中的所有元素出现的次数，则窗口中所有元素的
    // 最大值：ntimes.rbegin()->first 
    // 最小值：ntimes.begin()->first
    map<int, int> ntimes;
    int res = 1;
    while (r < nums.size()) {
      ntimes[nums[r++]]++;
      while (ntimes.rbegin()->first - ntimes.begin()->first > limit) {
        ntimes[nums[l]]--;
        if (ntimes[nums[l]] == 0) {
          ntimes.erase(nums[l]);
        }
        l++;
      }
      res = max(res, r - l);
    }
    return res;
  }
};

/**
 * 方法二：单调队列维护每一个最值
 */
class Solution {
 public:
  int longestSubarray(vector<int>& nums, int limit) {
    int l = 0, r = 0;
    int res = 1;
    deque<int> maxq; // 单调递减队列，维护滑动窗口中有可能成为最大值的序列
    deque<int> minq; // 单调递增队列，维护滑动窗口中有可能成为最小值的序列
    while (r < nums.size()) {
      // 维护最大值队列
      while (!maxq.empty() && nums[maxq.back()] < nums[r])
        maxq.pop_back();
      maxq.push_back(r);
      // 维护最小值队列
      while (!minq.empty() && nums[minq.back()] > nums[r])
        minq.pop_back();
      minq.push_back(r);

      // 若不满足限制，更新滑动窗口
      while (nums[maxq.front()] - nums[minq.front()] > limit) {
        if (maxq.front() == l) maxq.pop_front();
        if (minq.front() == l) minq.pop_front();
        l++;
      }
      r++;
      res = max(res, r - l);
    }
    return res;
  }
};