/**
 * https://leetcode.cn/problems/rectangle-overlap/
 * 区间相交问题 [a,b] [c,d] => [max(a,c), min(b,d)]
 * 先求出相交矩阵的左上角和右下角，判断是否是一个正常矩阵
 */
class Solution {
 public:
  bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
    // 左上角
    int x1 = max(rec1[0], rec2[0]);
    int y1 = max(rec1[1], rec2[1]);
    // 右下角
    int x2 = min(rec1[2], rec2[2]);
    int y2 = min(rec1[3], rec2[3]);
    return x1 < x2 && y1 < y2;
  }
};