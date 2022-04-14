/**
 * https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/
 * 方法一：大顶堆+
 */
class Solution {
 public:
  vector<int> getLeastNumbers(vector<int>& arr, int k) {
    if (k <= 0) return {};
    priority_queue<int> pq;

    for (int i = 0; i < arr.size(); i++) {
      if (i < k) {
        pq.push(arr[i]);
      } else {
        // 和堆顶比较，比堆顶小的要入堆
        if (pq.top() > arr[i]) {
          pq.pop();
          pq.push(arr[i]);
        }
      }
    }
    vector<int> res;
    while (!pq.empty()) {
      res.push_back(pq.top());
      pq.pop();
    }
    return res;
  }
};

/**
 * 方法二：partition+分治
 * 类似第 215 题，找到数组中第 k 小的数
 */
class Solution1 {
 public:
  vector<int> getLeastNumbers(vector<int>& arr, int k) {
    int l = 0;
    int r = arr.size() - 1;
    while (l < r) {
      int p = patition(arr, l, r);
      if (p + 1 == k) {
        break;
      } else if (p < k) {
        l = p + 1;
      } else {
        r = p - 1;
      }
    }
    return vector<int>(arr.begin(), arr.begin() + k);
  }

  int partition(vector<int>& arr, int l, int r) {
    // random poivt
    int t = l + rand() % (r - l + 1);
    swap(arr[t], arr[l]);
    int poivt = arr[l];
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