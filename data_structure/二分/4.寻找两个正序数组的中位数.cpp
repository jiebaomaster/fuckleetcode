/**
 * https://leetcode.cn/problems/median-of-two-sorted-arrays/
 * 方法一：2路归并，每次选出一个数，直到选到中位数
 */
class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    int target = (n + m) / 2;

    int pre, cur; // 记录 pre，处理偶数长度
    int i = 0, j = 0;
    int k = 0;
    while ((i < n || j < m) && k <= target) {
      pre = cur;
      int l = i < n ? nums1[i] : INT_MAX; // 超出长度的用极大值代替
      int r = j < m ? nums2[j] : INT_MAX;
      if (l <= r) { // 选出较小的
        cur = nums1[i];
        i++;
      } else {
        cur = nums2[j];
        j++;
      }
      k++;
    }

    if ((n + m) % 2 == 0) {
      return (pre + cur) / 2.0;
    } else {
      return cur;
    }
  }
};

/**
 * https://leetcode.cn/problems/median-of-two-sorted-arrays/solution/xun-zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-s-114/
 * 方法二：k/2 步长找两个有序数组的第 k 大数
 */
class Solution {
 public:
  // 求两个有序数组的第 k 大数，k 从 1 开始计数
  int findKthOfSortedArrays(vector<int>& nums1, vector<int>& nums2, int k) {
    int n = nums1.size();
    int m = nums2.size();
    int i = 0, j = 0;
    while (true) {
      // 有一边求完了，结果就在另一边
      if (i == n) return nums2[j + k - 1];
      if (j == m) return nums1[i + k - 1];
      // k==1
      if (k == 1) return min(nums1[i], nums2[j]);
      // 每次淘汰 k/2 个
      int move = k / 2 - 1;
      int nexti = i + move < n ? i + move : n - 1;
      int nextj = j + move < m ? j + move : m - 1;
      if (nums1[nexti] <= nums2[nextj]) {
        k -= nexti - i + 1;
        i = nexti + 1;
      } else {
        k -= nextj - j + 1;
        j = nextj + 1;
      }
    }
  }

  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();

    if ((n + m) % 2) {
      // 奇数长度，求 k = (n + m) / 2 + 1
      return findKthOfSortedArrays(nums1, nums2, (n + m) / 2 + 1);
    } else {
      // 偶数长度，求 k = (n + m) / 2 + 1 和 k = (n + m) / 2
      return (findKthOfSortedArrays(nums1, nums2, (n + m) / 2 + 1) +
              findKthOfSortedArrays(nums1, nums2, (n + m) / 2)) /
             2.0;
    }
  }
};