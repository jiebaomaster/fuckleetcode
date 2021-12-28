/**
 * https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/
 * https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/solution/c-zong-jie-liao-hui-su-wen-ti-lei-xing-dai-ni-ga-4/
 * 本题思路与 47 题完全一样，只是把数字换成了字母
 */
class Solution {
 public:
  vector<string> res;
  vector<string> permutation(string s) {
    string track;  // 路径
    // 记录 nums[i] 有没有出现在路径中，每个 nums[i] 只能使用一次
    vector<bool> used(s.size(), false);
    // 给数组排序，使重复的元素排列在一起
    sort(s.begin(), s.end());
    backtracking(track, s, used);
    return res;
  }
  void backtracking(string& track, string& s, vector<bool>& used) {
    if (track.size() == s.size()) {  // 满足结束条件
      res.push_back(track);
      return;
    }

    // 任意字母都可能出现在当前位置，只要其不曾在路径中出现过，且不重复
    for (int i = 0; i < s.size(); i++) {
      if (used[i])  // nums[i] 已在路径中，跳过
        continue;

      // s[i] == s[i - 1] 排除了重复的选项
      // !used[i-1] 保证了第一次出现的重复元素可以被子集选中，
      // 例如 [1 2 2] 中第二个 2 不应该在选择第一个位置的元素时被选中，
      // 但是应该在第一个元素是 2 时，可以被选为第二个元素，即子集 [2 2]
      if (i > 0 && s[i] == s[i - 1] && !used[i - 1]) continue;

      track.push_back(s[i]);  // 做选择
      used[i] = true;
      backtracking(track, s, used);
      used[i] = false;
      track.pop_back();  // 撤销选择
    }
  }
};