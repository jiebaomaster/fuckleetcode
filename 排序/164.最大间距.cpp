/**
 * https://leetcode.cn/problems/maximum-gap/
 * https://baike.baidu.com/item/%E5%9F%BA%E6%95%B0%E6%8E%92%E5%BA%8F
 * 基数排序
 */
class Solution {
 public:
  int maximumGap(vector<int>& nums) {
    radixSort(nums);
    int res = 0;
    for (int i = 1; i < nums.size(); i++) {
      res = max(res, nums[i] - nums[i - 1]);
    }
    return res;
  }
  
  void radixSort(vector<int>& nums) {
    long d = 1;
    vector<vector<int>> buckets(10);
    // 每次按一位，分配到 0～9 的桶中，指导所有的位都排序过
    for (int i = 0; i <= 9; i++) {
      for (auto n : nums) { // 分配到基数桶中
        int c = (n / d) % 10;
        buckets[c].push_back(n);
      }
      d *= 10;
      nums.clear();
      for (auto& b : buckets) { // 回收桶内元素
        for (auto n : b) {
          nums.push_back(n);
        }
        b.clear();
      }
    }
  }
};