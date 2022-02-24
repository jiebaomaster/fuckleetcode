/**
 * https://leetcode-cn.com/problems/pancake-sorting/
 * https://labuladong.github.io/algo/4/32/133/
 * https://leetcode-cn.com/problems/pancake-sorting/solution/jian-bing-pai-xu-by-leetcode/
 * 通过翻转操作给数组排序
 * 
 * 每次将 arr[0~n] 中最大的数排到最后面
 *  1. 先找到最大的数 arr[i] ，翻转 i 使 arr[i] 到煎饼堆的最上面，
 *  2. 再翻转 n 使 arr[i] 到煎饼堆的最下面
 */
class Solution {
 public:
  vector<int> tracking;
  vector<int> pancakeSort(vector<int>& arr) {
    doSort(arr, arr.size() - 1);
    return tracking;
  }
  // 将 arr[0~n] 排好序
  void doSort(vector<int>& arr, int n) {
    if (n == 0) return;

    // 先找到最大的数 arr[i]
    int maxPancakeIndex = 0;
    for (int i = 1; i <= n; i++) {
      if (arr[i] > arr[maxPancakeIndex]) {
        maxPancakeIndex = i;
      }
    }
    // 翻转最大数
    tracking.push_back(maxPancakeIndex + 1);
    arrReverse(arr, maxPancakeIndex);
    // 翻转底部
    tracking.push_back(n + 1);
    arrReverse(arr, n);
    // 排序 arr[0~n-1]
    doSort(arr, n - 1);
  }
  // 翻转 0～right
  void arrReverse(vector<int>& arr, int right) {
    int left = 0;
    while (left < right) {
      swap(arr[left], arr[right]);
      left++;
      right--;
    }
  }
};