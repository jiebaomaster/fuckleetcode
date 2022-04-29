/**
 * https://leetcode-cn.com/problems/rotate-array/
 * 将数组末尾 k 个元素移动到数组开头
 *
 * 方法一：将末尾 k 个数向前冒泡，会超时
 */
class Solution1 {
 public:
  void rotate(vector<int>& nums, int k) {
    for (int i = 1; i <= k; i++) {
      int j = nums.size() - 1;
      while (j > 0) {
        swap(nums[j], nums[j - 1]);
        j--;
      }
    }
  }
};

/**
 * 方法二：利用辅助空间，
 * 先输出 [n-k,n) 到辅助空间，再输出 [0,n-k) 到辅助空间
 */
class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;
    if (!k) return;
    vector<int> res;
    for (int i = n - k; i < n; i++) {
      res.push_back(nums[i]);
    }
    for (int i = 0; i < n - k; i++) {
      res.push_back(nums[i]);
    }
    nums = res;
  }
};

/**
 * 方法三：类似于左旋转字符串，先局部翻转再整体翻转
 */
class Solution2 {
 public:
  void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;
    if (!k) return;
    reverse(nums.begin(), nums.end() - k);
    reverse(nums.end() - k, nums.end());
    reverse(nums.begin(), nums.end());
  }
};