/**
 * https://leetcode.cn/problems/132-pattern/
 * 对比第 334 题 123 排列，可以贪心解决
 * 本地求 132 即 min max mid 的极大值排列模式
 *
 * 方法一：保证 min 和 max，寻找满足条件的 mid
 * O(n^2) 会超时
 */
class Solution {
 public:
  bool find132pattern(vector<int>& nums) {
    int leftmin = nums[0];  // max 左边的最小值，保证 min 和 max 的关系
    for (int i = 1; i < nums.size(); i++) {  // 遍历 max
      if (leftmin >= nums[i]) {
        leftmin = nums[i];
        continue;
      }
      for (int j = i + 1; j < nums.size();
           j++) {  // 在 max 右边寻找满足条件的 mid
        if (leftmin < nums[j] && nums[i] > nums[j]) return true;
      }
    }
    return false;
  }
};

/**
 * https://leetcode.cn/problems/132-pattern/solution/xiang-xin-ke-xue-xi-lie-xiang-jie-wei-he-95gt/
 * 方法二：单调栈
 *
 */
class Solution {
 public:
  bool find132pattern(vector<int>& nums) {
    stack<int> st; // 递减栈
    int mid = INT_MIN;
    for (int i = nums.size() - 1; i >= 0; i--) {
      if (nums[i] < mid) return true;

      while (!st.empty() && nums[st.top()] < nums[i]) {
        // mid 来源于栈
        // 栈顶 < nums[i]，即保证了 32
        mid = nums[st.top()]; 
        st.pop();
      }
      st.push(i);
    }
    return false;
  }
};