/**
 * https://leetcode.cn/problems/smallest-k-lcci/
 * 快排 partition
 */
class Solution {
 public:
  vector<int> smallestK(vector<int>& arr, int k) {
    int l = 0, r = arr.size() - 1;
    while (l < r) {
      int mid = partition(arr, l, r);
      if (mid == k) {
        break;
      } else if (mid < k) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return vector<int>(arr.begin(), arr.begin() + k);
  }

  int partition(vector<int>& arr, int l, int r) {
    int poivt = l + rand() % (r - l + 1);
    swap(arr[poivt], arr[l]);
    poivt = arr[l];
    while (l < r) {
      while (l < r && arr[r] >= poivt) r--;
      arr[l] = arr[r];
      while (l < r && arr[l] <= poivt) l++;
      arr[r] = arr[l];
    }
    arr[l] = poivt;
    return l;
  }
};