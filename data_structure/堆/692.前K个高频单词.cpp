/**
 * https://leetcode.cn/problems/top-k-frequent-words/
 * 类似于第 347 题，区别在于对同频率的元素，要按字典序返回
 * 最终返回的顺序是，频率递减，字典序递增
 * 则小顶堆中的顺序是，优先小频率，频率相同时，优先字典序大的
 * 这样字典序大的会被优先踢出堆
 * 最后从堆中导出数据时，需要进行一次逆序
 */
class Solution {
 public:
  vector<string> topKFrequent(vector<string> &words, int k) {
    unordered_map<string, int> times;
    for (auto &s : words) {
      times[s]++;
    }

    auto cmp = [](const pair<string, int> &lhs, const pair<string, int> &rhs) {
      if (lhs.second != rhs.second) // 频率从小到大
        return lhs.second > rhs.second;
      else // 字典序从大到小
        return lhs.first < rhs.first;
    };
    priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)>
        heap(cmp);

    for (auto &st : times) {
      if (heap.size() < k) {
        heap.push(st);
      } else if (!cmp(heap.top(), st)) {
        heap.pop();
        heap.push(st);
      }
    }

    vector<string> res;
    while (heap.size()) {
      res.push_back(heap.top().first);
      heap.pop();
    }
    reverse(res.begin(), res.end());
    return res;
  }
};