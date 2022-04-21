/**
 * https://leetcode-cn.com/problems/shuffle-an-array/
 * https://leetcode-cn.com/problems/shuffle-an-array/solution/gong-shui-san-xie-xi-pai-suan-fa-yun-yon-0qmy/
 * Knuth-Shuffle 洗牌算法
 * 对第 i 个数，与 [i, n) 中随机的一个数交换
 */
class Solution {
 public:
  vector<int> nums;
  Solution(vector<int>& nums) : nums(nums) {}

  vector<int> reset() { return nums; }

  vector<int> shuffle() {
    vector<int> res = nums;
    // 洗每一张牌
    for (int i = 0; i < res.size(); i++)
      swap(res[i], res[i + rand() % (res.size() - i)]);
    return res;
  }
};