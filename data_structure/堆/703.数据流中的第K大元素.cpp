/**
 * https://leetcode.cn/problems/kth-largest-element-in-a-stream/
 * 大小为 k 的小顶堆，堆顶就是第 k 大的元素
 */
class KthLargest {
 public:
  priority_queue<int, vector<int>, greater<int>> heap;
  int k;
  KthLargest(int k, vector<int>& nums) : k(k) {
    for (auto n : nums) add(n);
  }

  int add(int val) {
    if (heap.size() < k) {
      heap.push(val);
    } else if (val > heap.top()) {
      heap.pop();
      heap.push(val);
    }
    return heap.top();
  }
};
