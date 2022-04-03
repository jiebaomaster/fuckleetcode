/**
 * https://leetcode-cn.com/problems/longest-consecutive-sequence/
 * 找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
 *
 * 最简单的方法，给数组排序，然后遍历一次数组寻找
 */
class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    if (nums.empty()) return 0;
    // 排序后就可以找连续了
    sort(nums.begin(), nums.end());
    int cur = 1;
    int ret = 1;
    int pre = nums[0];  // 记录前一个数的值，处理重复的数字
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] == pre) {  // 跳过重复的数字
        continue;
      } else if (nums[i] == pre + 1) {  // 遇到一个连续的
        pre = nums[i];
        cur++;
        ret = max(ret, cur);
      } else {  // 遇到不连续的
        pre = nums[i];
        cur = 1;
      }
    }
    return ret;
  }
};

/**
 * https://leetcode-cn.com/problems/longest-consecutive-sequence/solution/zui-chang-lian-xu-xu-lie-by-leetcode-solution/
 * 考虑枚举数组中的每个数 x，考虑以其为起点，不断尝试匹配 x+1, x+2, ⋯ 是否存在，
 * 假设最长匹配到了 x+y，那么以 x 为起点的最长连续序列
 * 即为 x, x+1, x+2, ..., x+y，其长度为 y+1
 * 
 * 借助哈希表使得寻找 x+k 是否存在的时间复杂度为 O(n)
 */
class Solution1 {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> hash;
    // 所有元素存入哈希表中
    for (int n : nums) {
      hash.insert(n);
    }

    int ret = 0;
    // 遍历哈希表中的每个元素
    for (int n : hash) {
      if (!hash.count(n - 1)) { // n-1 不存在，则只需要找比 n 大的
        int len = 0;
        // 记录 n, n+1, n+2, ... 的个数
        while (hash.count(n++)) {
          len++;
        }
        ret = max(ret, len);
      }
    }

    return ret;
  }
};