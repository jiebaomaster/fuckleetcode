/**
 * https://leetcode.cn/problems/xor-queries-of-a-subarray/
 * 前缀和变成了前缀异或，操作都是一样的
 */
class Solution {
 public:
  vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    vector<int> prefix(arr.size() + 1);
    for (int i = 1; i <= arr.size(); i++) {
      prefix[i] = prefix[i - 1] ^ arr[i - 1];
    }

    vector<int> res;
    for (auto& q : queries) {
      res.push_back(prefix[q[1] + 1] ^ prefix[q[0]]);
    }
    return res;
  }
};