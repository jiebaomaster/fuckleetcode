/**
 * https://leetcode-cn.com/problems/advantage-shuffle/
 * https://labuladong.github.io/algo/2/20/61/
 */
class Solution {
 public:
  vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res(nums1.size());
    // 将 nums1 按降序排列
    sort(nums1.begin(), nums1.end(), greater<int>());
    // 将 nums2
    // 按降序存储到一个优先级队列里，pair<下标，值>，通过下标可得每一次匹配是结果中的哪个位置的值
    auto cmp = [](const pair<int, int>& l, const pair<int, int>& r) {
      return l.second < r.second;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(
        cmp);
    for (int i = 0; i < nums2.size(); i++) pq.push({i, nums2[i]});

    // nums1的首尾指针，分别指向最大值和最小值
    int l = 0, r = nums1.size() - 1;
    while (!pq.empty()) {  // 遍历nums2中的所有元素，在nums1中寻找最佳匹配
      auto cur = pq.top();
      pq.pop();
      // 比得过就比，比不过就送
      if (nums1[l] > cur.second) {
        // 当前nums1中最大的相比nums2中最大的有优势，匹配成功
        res[cur.first] = nums1[l++];
      } else {
        // 否则，采用nums1中最小的匹配nums2中最大的，田忌赛马策略
        res[cur.first] = nums1[r--];
      }
    }
    return res;
  }
};