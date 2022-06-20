/**
 * https://leetcode.cn/problems/maximum-product-of-three-numbers/
 * 在数组中找出由三个数组成的最大乘积
 * 如果数组中全是非负数，则排序后最大的三个数相乘即为最大乘积；
 * 如果全是非正数，则最大的三个数相乘同样也为最大乘积。
 * 如果数组中有正数有负数，则最大乘积既可能是三个最大正数的乘积，也可能是两个最小负数（即绝对值最大）与最大正数的乘积。
 */
class Solution {
 public:
  int maximumProduct(vector<int>& nums) {
    int n = nums.size();
    int max_1 = INT_MIN, max_2 = INT_MIN, max_3 = INT_MIN;
    int min_1 = INT_MAX, min_2 = INT_MAX;
    for (int n : nums) {
      if (n < min_1) {
        min_2 = min_1;
        min_1 = n;
      } else if (n < min_2) {
        min_2 = n;
      }

      if (n > max_1) {
        max_3 = max_2;
        max_2 = max_1;
        max_1 = n;
      } else if (n > max_2) {
        max_3 = max_2;
        max_2 = n;
      } else if (n > max_3) {
        max_3 = n;
      }
    }
    return max(max_1 * max_2 * max_3, max_1 * min_1 * min_2);
  }
};