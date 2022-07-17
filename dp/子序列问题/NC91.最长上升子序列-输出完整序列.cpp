/**
 * https://www.nowcoder.com/practice/9cf027bf54714ad889d4f30ff0ae5481?tpId=117&rp=1&ru=%2Fexam%2Foj&qru=%2Fexam%2Foj&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=&judgeStatus=&tags=&title=91&gioEnter=menu
 * 类似第 300 题，区别在于要求出具体的最长上升子序列
 */
class Solution {
 public:
  vector<int> LIS(vector<int>& arr) {
    // 1. 先求出最长上升子序列的长度
    int m = arr.size();
    vector<int> tail(m); // tail[i] 长度为 i 的最长上升子序列末尾元素，tail 本身是递增的
    vector<int> maxlen(m); // maxlen[i] 以 arr[i] 结尾的最长上升子序列长度
    int len = 0;
    for (int i = 0; i < m; i++) {
      int l = 0;
      int r = len;
      while (l < r) {
        int mid = (r + l) >> 1;
        if (tail[mid] >= arr[i])
          r = mid;
        else
          l = mid + 1;
      }
      tail[l] = arr[i];
      // 在求最长长度时，求出每个 arr[i] 结尾的最长长度时
      maxlen[i] = l + 1;
      if (len == l) len++;
    }
    // 2. 利用 maxlen[i] 求一个最长上升子序列
    // 从后向前查找 maxlen，依次找出每一个子序列的元素，
    // 若最长长度为 len，则要找的第一个元素的 maxlen[i] == len，以此类推
    vector<int> res(len);
    for (int i = m - 1; len > 0; i--) {
      if (maxlen[i] == len) {
        res[--len] = arr[i];
      }
    }
    return res;
  }
};