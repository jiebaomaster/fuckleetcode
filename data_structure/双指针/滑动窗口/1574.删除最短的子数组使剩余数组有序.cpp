/**
 * https://leetcode-cn.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/
 * https://leetcode-cn.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/solution/shan-chu-lian-xu-zi-shu-zu-by-taicailea-tp0t/
 */
class Solution {
 public:
  int findLengthOfShortestSubarray(vector<int>& arr) {
    // 找到数组最左边递增的最后一个位置
    int i = 0;
    while (i < arr.size() - 1 && arr[i] <= arr[i + 1]) i++;
    // 找到数组最右边递增的开始位置
    int j = arr.size() - 1;
    while (j > 0 && arr[j] >= arr[j - 1]) j--;
    if (j == 0) return 0;
    // 中间的子数组 [i+1,j-1] 肯定是要删除的，因为只能删除一个连续的子数组
    // 最小值可能是删除 [i+1...] 或者删除 [...j-1]
    int ret = min((int)arr.size() - i - 1, j);
    // 遍历左边数组的每一个位置，找到右边数组相应的非递减的端点
    for (int s = 0; s <= i; s++) {
      int l = j, r = arr.size();
      while (l < r) { // 在右边数组二分查找第一个不小于 arr[s] 的
        int mid = l + (r - l) / 2;
        if (arr[mid] < arr[s])
          l = mid + 1;
        else
          r = mid;
      }
      // 此时有 arr[s] <= arr[l]，删除 [s+1, l-1]
      ret = min(ret, l - s - 1);
    }
    return ret;
  }
};