/**
 * https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/
 * https://labuladong.gitbook.io/algo/mu-lu-ye-1/mu-lu-ye-4/shuang-zhi-zhen-ji-qiao#er-zuo-you-zhi-zhen-de-chang-yong-suan-fa
 */
class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    // 由数组的有序性，可以用双指针夹逼法
    int left = 0, right = numbers.size() - 1;
    while (left < right) {
      int tmp = numbers[left] + numbers[right];
      if (tmp == target) {  // 找到目标
        return {left + 1, right + 1};
      } else if (tmp > target) {  // 太大了，要减小
        right--;
      } else {  // 太小了，要增大
        left++;
      }
    }
    return {-1, -1};
  }
};