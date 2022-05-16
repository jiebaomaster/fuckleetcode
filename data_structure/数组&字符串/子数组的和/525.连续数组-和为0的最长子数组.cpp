/**
 * https://leetcode.cn/problems/contiguous-array/
 * 方法一：前缀和
 * 要使连续数组中0和1的数量相同，只要区间和等于区间长度的一半
 * 区间和可以借助前缀和求解，
 * 以每个i为区间终点，寻找区间起点，满足区间和等于区间长度的一半，需要一个双层循环
 * 此方法超时
 */
class Solution {
 public:
  int findMaxLength(vector<int>& nums) {
    vector<int> prefix(nums.size() + 1);
    for (int i = 1; i <= nums.size(); i++) {
      prefix[i] = prefix[i - 1] + nums[i - 1];
    }

    int res = 0;
    for (int i = 1; i <= nums.size(); i++) {
      for (int j = 0; j < i; j++) {
        if ((prefix[i] - prefix[j]) * 2 == i - j) {
          res = max(res, i - j);
          break;
        }
      }
    }

    return res;
  }
};

/**
 * https://leetcode.cn/problems/contiguous-array/solution/dong-tu-yan-shi-qian-zhui-he-si-xiang-by-z2no/
 * 方法二：前缀和 + 哈希
 * 上面的方法需要双层循环找区间，
 * 将数组中的 0 看作 -1，可以将找区间问题转化为前缀和是否已经出现过的问题
 * 由于碰1加一，碰0减一，当0与1数量一致时(连续数组), 其连续数组的和为零
 * 用一个哈希表记录前缀和出现的最早位置
 */
class Solution {
 public:
  int findMaxLength(vector<int>& nums) {
    // 记录前缀和出现的最早位置
    // 插入{0,-1}，处理连续数组的起始点在 index == 0 的位置的情况
    map<int, int> n_index = {{0, -1}};
    int cur = 0; // 前缀和
    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
      cur += nums[i] ? 1 : -1;
      if (n_index.count(cur)) { // 出现过的前缀和，更新结果
        res = max(res, i - n_index[cur]);
      } else {
        n_index[cur] = i; // 0～i 和为 cur
      }
    }

    return res;
  }
};