/**
 * https://leetcode.cn/problems/count-of-smaller-numbers-after-self/
 * 类似于逆序对，只不过要求输出的结果更具体：要求计算每一个元素的右边有多少个元素比自己小
 * 归并时，需要知道当前操作的元素在原数组中的位置，可以使用下标数组技巧，
 * 对下标数组进行 从大到小 的归并排序，
 * 当左半边的元素 xl 被选中时，右半边剩余的所有元素都比 xl 小
 */
class Solution {
 public:
  vector<int> countSmaller(vector<int> &nums) {
    int n = nums.size();
    vector<int> res(n);
    vector<int> index(n); // 下标数组
    vector<int> buf(n);
    for (int i = 0; i < n; i++) {
      index[i] = i;
    }
    mergeSort(res, nums, index, buf, 0, n - 1);
    return res;
  }
  void mergeSort(vector<int> &res, vector<int> &nums, vector<int> &index,
                 vector<int> &buf, int i, int j) {
    if (i >= j) return;
    int mid = i + (j - i) / 2;
    mergeSort(res, nums, index, buf, i, mid);
    mergeSort(res, nums, index, buf, mid + 1, j);

    int p = i, q = mid + 1;
    int k = i;
    while (p <= mid && q <= j) {
      if (nums[index[p]] > nums[index[q]]) {
        buf[k++] = index[p];
        // 当左半边的元素 xl 被选中时，右半边剩余的所有元素都比 xl 小
        // 右半边剩余的元素个数为 j-q+1
        res[index[p]] += j - q + 1;
        p++;
      } else {
        buf[k++] = index[q++];
      }
    }
    while (p <= mid) buf[k++] = index[p++];
    while (q <= j) buf[k++] = index[q++];

    while (i <= j) {
      index[i] = buf[i];
      i++;
    }
  }
};