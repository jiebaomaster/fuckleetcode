/**
 * https://leetcode-cn.com/problems/two-sum/
 * 本题不能使用双指针法，因为双指针必须要排序，排序后不能返回数组下标
 */
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hash; // num -> index
    // 所有数据存入hash表
    for (int i = 0; i < nums.size(); i++) {
      hash[nums[i]] = i;
    }
    // 要找 nums[i] + x = target 即在hash表中寻找 x = target - nums[i]
    for (int i = 0; i < nums.size(); i++) {
      int half = target - nums[i];
      if (hash.find(half) != hash.end()) {
        if (hash[half] == i) // 数组中同一个元素在答案里不能重复出现
          continue;
        return {i, hash[half]};
      }
    }
    return {};
  }
};