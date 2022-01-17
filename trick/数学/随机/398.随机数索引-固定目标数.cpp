/**
 * https://leetcode-cn.com/problems/random-pick-index/
 * https://leetcode-cn.com/problems/linked-list-random-node/solution/xu-shui-chi-chou-yang-suan-fa-by-jackwener/
 */
class Solution {
  vector<int>* nums_;

 public:
  Solution(vector<int>& nums) { nums_ = &nums; }

  int pick(int target) {
    int sz = nums_->size();
    int cnt = 1;
    int ret;
    for (int i = 0; i < sz; i++) {
      // 随机选择 target，遇到 target 才开始计数
      if (nums_->at(i) == target) {
        // 一个随机数可以被 cnt 整除的概率是 1/cnt
        // 1/cnt 的概率选中当前节点
        if (rand() % cnt == 0) {
          ret = i;
        }
        cnt++;
      }
    }
    return ret;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */