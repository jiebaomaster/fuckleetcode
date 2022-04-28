/**
 * https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/
 * 
 */
class Solution {
 public:
  string minNumber(vector<int>& nums) {
    auto cmp = [](int lhs, int rhs) {
      string l = to_string(lhs);
      string r = to_string(rhs);
      return l + r < r + l;
    };
    sort(nums.begin(), nums.end(), cmp);
    string res;
    for (auto n : nums) {
      res += to_string(n);
    }
    return res;
  }
};