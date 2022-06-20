/**
 * https://leetcode.cn/problems/permutation-sequence/
 * 求 n 个数的第 k 个排列
 * 方法一：直接回溯排列，找到第 k 个
 */
class Solution {
 public:
  string getPermutation(int n, int k) {
    vector<int> track(n);
    vector<bool> used(n + 1, false);

    backtrace(used, track, 0, k, n);
    string res;
    for (auto t : track) {
      res.push_back(t + '0');
    }
    return res;
  }

  bool backtrace(vector<bool> &used, vector<int> &track, int index, int &k,
                 int n) {
    if (index == n) {
      k--;
      return k == 0;
    }

    for (int i = 1; i <= n; i++) {
      if (used[i]) continue;

      used[i] = true;
      track[index] = i;
      if (backtrace(used, track, index + 1, k, n)) return true;
      used[i] = false;
    }
    return false;
  }
};

/**
 * https://leetcode.cn/problems/permutation-sequence/solution/hui-su-jian-zhi-python-dai-ma-java-dai-ma-by-liwei/
 * 方法二：数学剪枝
 */
class Solution {
 public:
  string getPermutation(int n, int k) {
    // 计算 0～n 的阶乘
    vector<int> f(n + 1);
    f[0] = 1;
    for (int i = 1; i <= n; i++) f[i] = f[i - 1] * i;

    vector<int> track(n);
    vector<bool> used(n + 1, false);

    backtrace(used, track, 0, k, n, f);
    string res;
    for (auto t : track) {
      res.push_back(t + '0');
    }
    return res;
  }

  void backtrace(vector<bool> &used, vector<int> &track, int index, int &k,
                 int n, vector<int> &f) {
    if (index == n) return;

    // 选中当前第 index 个后，剩余待选元素会产生几个排列
    int t = f[n - index - 1];
    for (int i = 1; i <= n; i++) {
      if (used[i]) continue;
      // 选中 i 时产生的排列达不到 k，说明本位不应该选 i
      if (t < k) {
        k -= t; // 省去了 t 个排列
        continue;
      }
      used[i] = true;
      track[index] = i;
      // 递归选择下一位的数
      backtrace(used, track, index + 1, k, n, f);
      // 不用回溯，找到 k 之后的数没必要尝试了
      return;
    }
  }
};