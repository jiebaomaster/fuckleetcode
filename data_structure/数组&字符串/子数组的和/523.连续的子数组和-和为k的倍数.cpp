/**
 * https://leetcode.cn/problems/continuous-subarray-sum/
 * https://leetcode.cn/problems/continuous-subarray-sum/solution/lian-xu-de-zi-shu-zu-he-by-leetcode-solu-rdzi/
 * 同余定理：想要 b - a 为 k 的倍数，只需要确保 b 和 a 模 k 相同即可
 * 
 * 本题中要判断是否存在 prefix 使 cur - prefix 为 k 的倍数，
 * 只需要判断是否存在 prefix 使 prefix % k 等于 cur % k，
 * 即判断 cur % k 是否存在
 */
class Solution {
 public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    int cur = 0;
    map<int, int> n_index = {{0, -1}};
    for (int i = 0; i < nums.size(); i++) {
      cur += nums[i];

      if (n_index.count(cur % k)) { // k 的倍数
        if (i - n_index[cur % k] >= 2) { // 长度至少为 2
          return true;
        }
      } else {
        n_index[cur % k] = i;
      }
    }
    return false;
  }
};