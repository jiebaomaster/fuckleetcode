/**
 * https://leetcode-cn.com/problems/hand-of-straights/
 * 相比于 659.分割数组为连续子序列，本题要求分割后的子序列长度必须为 groupSize
 */
class Solution {
 public:
  bool isNStraightHand(vector<int>& hand, int groupSize) {
    if (hand.size() % groupSize) // 数组长度必须为 groupSize 的整数倍
      return false;
    // 先升序排序
    sort(hand.begin(), hand.end());
    // 哈希表的键为子序列的最后一个数字，值为小顶堆，用于存储所有的子序列长度
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> end_size;
    // 尝试将每个数字分配到某个子序列中
    for (int n : hand) {
      // 默认情况下，n 新建一个以 n 结尾的子序列
      int len = 1;
      // 如果哈希表中存在以 n-1 结尾的子序列，则将 n 分配到这些子序列中长度最小的子序列中，即堆顶
      if (end_size.find(n - 1) != end_size.end()) {
        // 如果被选中的子序列长度已经达到 groupSize，则 n 应该新建子序列
        if (end_size[n - 1].top() < groupSize) {
          len = end_size[n - 1].top() + 1;
          end_size[n - 1].pop();
          if (end_size[n - 1].empty()) {
            end_size.erase(n - 1);
          }
        }
      }
      // 将以 n 结尾的子序列加入哈希表
      if (end_size.find(n) == end_size.end()) {
        end_size[n] = priority_queue<int, vector<int>, greater<int>>();
      }
      end_size[n].push(len);
    }
    // 检查所有的子序列长度
    for (auto& e : end_size) {
      auto heap = e.second;
      // c++ heap 不能直接遍历
      while (!heap.empty()) {
        if (heap.top() != groupSize) {
          return false;
        }
        heap.pop();
      }
    }
    return true;
  }
};