/**
 * https://leetcode.cn/problems/sort-characters-by-frequency/
 * 方法一：堆排序
 */
class Solution {
 public:
  string frequencySort(string s) {
    unordered_map<char, int> times;
    // 统计出现次数
    for (auto c : s) {
      times[c]++;
    }
    // 用大顶堆排序
    priority_queue<pair<int, char>> heap;
    for (auto &[c, t] : times) {
      heap.push({t, c});
    }
    // 出堆，还原字符串
    string res;
    while (!heap.empty()) {
      res += string(heap.top().first, heap.top().second);
      heap.pop();
    }
    return res;
  }
};

/**
 * 方法二：桶排序
 * 如果频率的最大值比较小，可以使用桶排序
 * 桶排序是以空间换时间的方法，O(n) 空间换取 O(n) 时间
 */
class Solution {
 public:
  string frequencySort(string s) {
    unordered_map<char, int> times;
    int maxFreq = 0;
    // 统计出现次数，计算最大频率
    for (auto c : s) {
      times[c]++;
      maxFreq = max(maxFreq, times[c]);
    }
    vector<vector<char>> buckets(maxFreq + 1);
    // 在对应频率的桶中加入字符
    for (auto &[c, t] : times) {
      buckets[t].push_back(c);
    }
    // 从最大次数倒序遍历每一个桶，拼接结果字符串
    string res;
    for (int i = maxFreq; i >= 0; i--) {
      for (auto c : buckets[i]) res += string(i, c);
    }
    return res;
  }
};