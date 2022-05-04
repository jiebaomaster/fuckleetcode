/**
 * https://leetcode-cn.com/problems/find-all-duplicates-in-an-array/
 * 
 *
 * 方法一：原地哈希，参考第 287 题
 * 由于本题中出现两次的数有多个
 */
class Solution {
 public:
  vector<int> findDuplicates(vector<int>& nums) {
    vector<int> res;
    for (int i = 0; i < nums.size();) {
      // 当前位置已哈希完成或者是一个待定的位置，跳到下一个位置
      if (nums[i] == i + 1 || nums[i] == -1) {
        i++;
        continue;
      } else {
        // nums[i] 处的位置已经完成哈希，找到重复数
        if (nums[i] == nums[nums[i] - 1]) {
          res.push_back(nums[i]);
          // -1 表示一个待定的位置
          nums[i] = -1;
          i++;
          continue;
        } else {  // 完成位置 nums[i] - 1 处的哈希
          swap(nums[i], nums[nums[i] - 1]);
        }
      }
    }
    return res;
  }
};

/**
 * 方法二：利用正负号表示是否已出现，参考第 448 题
 * 在输入数组中用数字的正负来表示该位置所对应数字是否已经出现过。
 * 遍历输入数组，给对应位置的数字取相反数，如果已经是负数，说明前面已经出现过，直接放入输出数组。
 */
class Solution {
 public:
  vector<int> findDuplicates(vector<int>& nums) {
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
      int cur = abs(nums[i]);
      if (nums[cur - 1] < 0) { // 已经是负数，说明前面已经出现过
        res.push_back(cur);
      } else { // cur 第一次出现，取相反数
        nums[cur - 1] *= -1;
      }
    }
    return res;
  }
};