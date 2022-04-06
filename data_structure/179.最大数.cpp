/**
 * https://leetcode-cn.com/problems/largest-number/
 */
class Solution {
 public:
  string largestNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end(), [](int pre, int cur) {
      string s1 = to_string(pre);
      string s2 = to_string(cur);
      return s1 + s2 > s2 + s1;
    });
    string res;
    for (int n : nums) {
      res += to_string(n);
    }
    if (res[0] == '0') return "0";
    return res;
  }
};