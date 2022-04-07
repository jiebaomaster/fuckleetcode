/**
 * https://leetcode-cn.com/problems/maximum-product-subarray/
 * https://leetcode-cn.com/problems/maximum-product-subarray/solution/cheng-ji-zui-da-zi-shu-zu-by-leetcode-solution/
 * 本题不能像 53 题一样由 dp[i] = max{dp[i-1]*n[i], n[i]} 得出。
 * 因为负数的存在导致 dp[i] 不止由 dp[i-1] 决定
 * 例如 n={5,6,-3,4,-3} 由上述公式可得 dp={5,30,-3,4,-3}，res=30，但是正确
 * 答案为所有数字相乘。考虑负负得正，需要记录最小值，即 双DP
 * 
 * 考虑当前位置如果是一个负数的话，那么我们希望以它前一个位置结尾的某个段的积也是个负数，
 * 这样就可以负负得正，并且我们希望这个积尽可能「负得更多」，即尽可能小。
 * 如果当前位置是一个正数的话，我们更希望以它前一个位置结尾的某个段的积也是个正数，
 * 并且希望它尽可能地大。
 * 于是这里我们可以再维护一个 dp_min，它表示以第 i 个元素结尾的乘积最小子数组的乘积
 */
class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    vector<int> dp_max(nums.size());
    vector<int> dp_min(nums.size());

    dp_max[0] = nums[0];
    dp_min[0] = nums[0];
    int res = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      dp_max[i] =
          max(max(dp_max[i - 1] * nums[i], dp_min[i - 1] * nums[i]), nums[i]);
      dp_min[i] =
          min(min(dp_max[i - 1] * nums[i], dp_min[i - 1] * nums[i]), nums[i]);
      res = max(max(dp_max[i], dp_min[i]), res);
    }
    return res;
  }
};