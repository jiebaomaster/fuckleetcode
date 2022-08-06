/**
 * https://leetcode.cn/problems/magnetic-force-between-two-balls/
 * 选取的球数越多，任意两球之间最小磁力越小
 * 
 * 如果 left=mid，则 else 语句 right=mid-1，mid = (left + right + 1) >> 1
 * 如果 right=mid，则 else 语句 left=mid+1，mid = (left + right) >> 1
 */
class Solution {
 public:
  // 求最小磁力为 n 时，最多可选球数
  int f(vector<int>& position, int n) {
    int cnt = 1;
    int cur = position[0];
    for (int i = 1; i < position.size(); i++) {
      if (position[i] - cur >= n) {
        cnt++;
        cur = position[i];
      }
    }
    return cnt;
  }
  int maxDistance(vector<int>& position, int m) {
    sort(position.begin(), position.end());
    int n = position.size();
    int l = 1;
    int r = position[n - 1] - position[0];

    while (l < r) {
      // 注意这里的二分查找，因为是 l = mid 所以 mid 向上取整
      int mid = (r + l + 1) / 2;
      if (f(position, mid) >= m)
        l = mid;
      else
        r = mid - 1;
    }
    return l;
  }
};