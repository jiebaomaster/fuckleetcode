/**
 * https://leetcode-cn.com/problems/split-array-into-consecutive-subsequences/
 * https://leetcode-cn.com/problems/split-array-into-consecutive-subsequences/solution/fen-ge-shu-zu-wei-lian-xu-zi-xu-lie-by-l-lbs5/
 * 判断一个整数序列是否能被分割成一个或多个长度至少为 3 的子序列，其中每个子序列都由连续整数组成
 */
class Solution {
 public:
  bool isPossible(vector<int>& nums) {
    // 哈希表的键为子序列的最后一个数字，值为小顶堆，用于存储所有的子序列长度，
    // 小顶堆满足堆顶的元素是最小的，因此堆顶的元素即为最小的子序列长度。
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> end_size;
    // 尝试将每个数字分配到某个子序列中
    for (int n : nums) {
      // 默认情况下，n 新建一个以 n 结尾的子序列
      int len = 1;
      // 如果哈希表中存在以 n-1 结尾的子序列，则将 n 分配到这些子序列中长度最小的子序列中，即堆顶
      if (end_size.find(n - 1) != end_size.end()) {
        len = end_size[n - 1].top() + 1;
        end_size[n - 1].pop();
        if (end_size[n - 1].empty()) {
          end_size.erase(n - 1);
        }
      }
      // 将以 n 结尾的子序列加入哈希表
      if (end_size.find(n) == end_size.end()) {
        end_size[n] = priority_queue<int, vector<int>, greater<int>>();
      }
      end_size[n].push(len);
    }
    // 检查所有的子序列长度，因为是小顶堆，只要检查堆顶子序列即可
    for (auto& b : end_size) {
      if (b.second.top() < 3) return false;
    }
    return true;
  }
};