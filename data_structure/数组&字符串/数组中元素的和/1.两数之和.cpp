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

/**
 * 方法二：一边哈希一边判断，遍历一次
 */
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> position;
    for (int i = 0; i < nums.size(); i++) {
      int t = target - nums[i];
      if (position.count(t)) {
        return {position[t], i};
      }
      // 先进行判断，再添加，就不会使用重复的元素了
      position[nums[i]] = i;
    }
    return {0, 0};
  }
};