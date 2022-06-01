/**
 * https://leetcode.cn/problems/sum-of-all-odd-length-subarrays/
 *
 */
class Solution {
 public:
  int sumOddLengthSubarrays(vector<int>& arr) {
    int n = arr.size();
    vector<int> prefix(n + 1);
    for (int i = 1; i <= n; i++) {
      prefix[i] = prefix[i - 1] + arr[i - 1];
    }

    int res = 0;
    for (int k = 1; k <= n; k += 2) { // 奇数步长
      for (int i = 0; i + k <= n; i++) { // 遍历该步长下的所有子数组
        res += prefix[i + k] - prefix[i];
      }
    }
    return res;
  }
};