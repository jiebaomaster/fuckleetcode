/**
 * https://leetcode-cn.com/problems/top-k-frequent-elements/
 * topK
 *
 * 方法一：小顶堆
 * 时间 hash O(n)+ heap O(nlogk)
 * 空间 hash O(n)+ heap O(k)
 */
class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> res;
    unordered_map<int, int> times;  // hash 记录元素的出现次数
    for (int n : nums) {            // 记录出现次数
      times[n]++;
    }

    // 小顶堆求 topk，利用 pair 的默认比较方法，先比较第一个元素再比较第二个
    // 元素的出现次数是pair的第一个元素，则堆按元素的出现次数排序
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        heap;
    // 遍历 hash，维护小顶堆，最后堆中留下的元素就是 topk
    for (auto& [n, ntimes] : times) {
      if (heap.size() < k) {
        heap.push({ntimes, n});
      } else {
        if (ntimes > heap.top().first) {
          heap.pop();
          heap.push({ntimes, n});
        }
      }
    }
    // 导出堆中的元素
    while (!heap.empty()) {
      res.push_back(heap.top().second);
      heap.pop();
    }
    return res;
  }
};

/**
 * 方法二：求频次数组的topk，即用快排求数组中第k大的元素
 * 时间 hash O(n) + 频次数组 O(n) + 快排 O(n)
 * 空间 hash O(n) + 频次数组 O(n)
 */
class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> times;
    for (int n : nums) {
      times[n]++;
    }
    // 组装频次数组
    vector<pair<int, int>> key_times;
    for (auto& [n, ntimes] : times) {
      key_times.push_back({n, ntimes});
    }
    // 前 k 大个元素，即 [n-k~n-1]，求第 n-k 大的元素
    k = key_times.size() - k;
    findTopK(key_times, k);
    vector<int> res;
    for (int i = k; i < key_times.size(); i++)
      res.push_back(key_times[i].first);

    return res;
  }

  // 二分法求第 k 大的
  void findTopK(vector<pair<int, int>>& key_times, int k) {
    int l = 0, r = key_times.size() - 1;
    while (l < r) {
      int mid = partition(key_times, l, r);
      if (mid == k) {
        return;
      } else if (mid < k) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
  }

  int partition(vector<pair<int, int>>& key_times, int l, int r) {
    int t = l + rand() % (r - l + 1);
    swap(key_times[l], key_times[t]);
    auto poivt = key_times[l];
    while (l < r) {
      while (l < r && poivt.second <= key_times[r].second) r--;
      key_times[l] = key_times[r];
      while (l < r && poivt.second >= key_times[l].second) l++;
      key_times[r] = key_times[l];
    }
    key_times[l] = poivt;
    return l;
  }
};