/**
 * https://leetcode-cn.com/problems/partition-to-k-equal-sum-subsets/
 * https://labuladong.gitee.io/algo/4/29/105/
 * 
 * 要将 n 个数字平均放入 k 个桶中，
 * 如果只有 2 个桶，可以等效为容量为 sum/2 的背包问题，即 416 题
 * 
 * 如果 k>2 只能用回溯算法解决。我们可以有两种视角：
 *  1. 站在 n 个数字的视角，每个数字都要选择进入到 k 个桶中的某一个。
 */
class Solution {
 public:
  bool canPartitionKSubsets(vector<int>& nums, int k) {
    if (k <= 0) return false;

    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % k) return false; // 不能整除的肯定不能平均装入
    vector<int> bucket(k); // k 个桶
    int target = sum / k; // 每个桶应该达到的数字

    // 更大的数字排在前面，有利于触发回溯中的剪枝操作，减少递归
    sort(nums.begin(), nums.end(), greater<int>());
    // 穷举，看看 nums 是否能划分成 k 个和为 target 的子集
    return backtracking(nums, 0, bucket, target);
  };

  /**
   * @brief 递归穷举 nums 中的每个数字，每个数字都要选择进入到 k 个桶中的某一个
   */
  bool backtracking(vector<int>& nums, int index, vector<int>& bucket,
                    int target) {
    if (index == nums.size()) {
      for (int i = 0; i < bucket.size(); i++)
        if (bucket[i] != target) return false;
      return true;
    }
    // 穷举 nums[index] 可能装入的桶
    for (int i = 0; i < bucket.size(); i++) {
      // 剪枝。如果当前数字装入第i个桶会使桶中数字过大，则跳过
      if (bucket[i] + nums[index] > target) continue;

      bucket[i] += nums[index]; // 将 nums[index] 装入 bucket[i]
      // 递归穷举下一个数字的选择，注意我们只要判断能不能，而不是记录所有可能性，所有一旦可以就返回
      if (backtracking(nums, index + 1, bucket, target)) return true;
      // 撤销选择
      bucket[i] -= nums[index];
    }

    // nums[index] 装入哪个桶都不行
    return false;
  }
};

/**
 * 2. 站在 k 个桶的视角，对于每个桶，都要遍历 n 个数字，然后选择是否将当前遍历到的数字装进自己这个桶里。
 */
