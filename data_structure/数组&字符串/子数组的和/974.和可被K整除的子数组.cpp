/**
 * https://leetcode.cn/problems/subarray-sums-divisible-by-k/
 * 同余定理： 如果两个数的差能被K整除，就说明这两个数 mod  K得到的结果相同
 * 为什么取模得到 负数，要加上 k 转为 整数？
 * 举例：K = 4，求得一个前缀和为 -1 ，一个前缀和为 3，  -1 % 4 = -1 ，3 % 4 = 3
 *   看似它们模的结果不相等，一个为 -1 ，一个为 3 ，但应该记到一组里
 *   因为它们前缀和之差：为 4 或 -4 。 4 % 4 = 0， -4 % 4 = 0
 *   所以要把前缀和模K的结果 -1，加上 K ，转成正数的 3
 *   这样就算前缀和是负数，模 K 后的结果一定在 [0,k-1],
 *    可以用一个数组记录前缀和 模K 后的结果个数
 */
class Solution {
 public:
  int subarraysDivByK(vector<int>& nums, int k) {
    int res = 0;
    int cur = 0;
    unordered_map<int, int> diff_times;
    diff_times[0]++;
    for (int i = 0; i < nums.size(); i++) {
      cur += nums[i];

      int mod = cur % k;
      if (mod < 0) mod += k; // 负数转正数
      if (diff_times.count(mod)) {
        res += diff_times[mod];
      }

      diff_times[mod]++;
    }
    return res;
  }
};