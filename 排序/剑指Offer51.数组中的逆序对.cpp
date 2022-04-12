/**
 * https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof/
 * 数组达到有序需要的元素间的交换次数与逆序对个数有关系，
 * 也就是说交换次数越多逆序对个数越少，则解法和排序有关
 */
class Solution {
 public:
  int cnt = 0;
  int reversePairs(vector<int>& nums) {
    vector<int> buf(nums.size());
    mergeSort(nums, 0, nums.size() - 1, buf);
    return cnt;
  }
  void mergeSort(vector<int>& nums, int l, int r, vector<int>& buf) {
    if (l >= r) return;
    int mid = l + (r - l) / 2;
    mergeSort(nums, l, mid, buf);
    mergeSort(nums, mid + 1, r, buf);

    int p = l;
    int sl = l;
    int sr = mid + 1;
    while (sl <= mid && sr <= r) {
      if (nums[sl] <= nums[sr]) {
        buf[p++] = nums[sl++];
      } else {
        buf[p++] = nums[sr++];
        /**
         * 只比递归排序加了这一句
         * 如果 nums[sl] <= nums[sr]，则[sl,sr]构成逆序对，
         * 且 [sl...mid] 都与 sr 构成逆序对
         */
        cnt += mid + 1 - sl;
      }
    }
    while (sl <= mid) {
      buf[p++] = nums[sl++];
    };
    while (sr <= r) buf[p++] = nums[sr++];

    while (l <= r) {
      nums[l] = buf[l];
      l++;
    }
  }
};