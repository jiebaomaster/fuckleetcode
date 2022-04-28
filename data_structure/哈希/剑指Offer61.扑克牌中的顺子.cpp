/**
 * https://leetcode-cn.com/problems/bu-ke-pai-zhong-de-shun-zi-lcof/
 * 大小为 5 的数组是个顺子需要满足两个条件：
 *  1. 没有重复数
 *  2. 最大数 - 最小数 < 5
 * 
 * 方法一：hash 判重
 */
class Solution {
 public:
  bool isStraight(vector<int>& nums) {
    unordered_set<int> hash;
    int maxN = 0;
    int minN = 15;
    for (int i = 0; i < 5; i++) {
      if (nums[i] == 0) continue;
      if (hash.count(nums[i])) return false;

      hash.insert(nums[i]);
      maxN = max(maxN, nums[i]);
      minN = min(minN, nums[i]);
    }
    return maxN - minN < 5;
  }
};

/**
 * 方法二：排序判重
 */
class Solution {
 public:
  bool isStraight(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int cnt = 0; // 统计大小王的个数
    for (int i = 0; i < 5; i++) {
      if (nums[i] == 0) {
        cnt++;
        continue;
      }

      if (i != 4 && nums[i] == nums[i + 1]) return false;
    }
    // 排序后最大值为最后一个元素，最小值为大小王之后的元素，大小王为0一定排在最前面
    return nums[4] - nums[cnt] < 5;
  }
};
