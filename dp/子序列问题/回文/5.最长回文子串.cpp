/**
 * https://leetcode-cn.com/problems/longest-palindromic-substring/
 * 区间dp。思路参考题 516，但是本体求的是连续子串 
 * dp[i][j] 表示区间范围[i,j]（注意是左闭右闭）的子串是否是回文子串
 */
class Solution {
 public:
  string longestPalindrome(string s) {
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), true));
    pair<int, int> maxPair = {0, 0}; // 最长子串的左右边界
    for (int i = s.size() - 1; i >= 0; i--) {
      for (int j = i + 1; j < s.size(); j++) {
        if (s[i] != s[j]  // 两端不相等则s[i...j]不是回文
            || !dp[i + 1][j - 1])  // 两端相等，但内部s[i+1...j-1]不是回文，则s[i...j]不是回文
          dp[i][j] = false;
        // 在得到[i,j]区间是否是回文子串的时候，可以更新最长回文子串的左右边界
        if (dp[i][j] && (j - i) > (maxPair.second - maxPair.first)) {
          maxPair = {i, j};
        }
      }
    }

    return s.substr(maxPair.first, maxPair.second - maxPair.first + 1);
  }
};

/**
 * 区间 DP 的状态压缩
 * 注意遍历方向，ij还是定义了区间的左右边界，但是dp改变只有一维了
 * dp 更新时不能缺省，必须明确设置
 */
class Solution {
 public:
  string longestPalindrome(string s) {
    pair<int, int> res;
    int n = s.size();
    vector<bool> dp(n, false);

    for (int i = n - 1; i >= 0; i--) {
      for (int j = n - 1; j >= i; j--) {
        if (i == j)
          dp[j] = true;
        else if (i + 1 == j) {
          dp[j] = s[i] == s[j];
        } else {
          dp[j] = s[i] == s[j] && dp[j - 1];
        }
        if (dp[j] && j - i > res.second - res.first) {
          res = {i, j};
        }
      }
    }

    return s.substr(res.first, res.second - res.first + 1);
  }
};

/**
 * 方法二：中心扩散法
 * 回文串具有轴对称性，只要取一个中心，然后尝试向两边扩散
 * 取中心点时，可以是一个元素也可以是两个元素
 */
class Solution {
 public:
  string longestPalindrome(string s) {
    pair<int, int> res;
    for (int i = 0; i < s.size(); i++) {
      auto p = expand(s, i, i);
      if (res.second - res.first < p.second - p.first) {
        res = p;
      }
      if (i > 0 && s[i - 1] == s[i]) {
        auto p2 = expand(s, i - 1, i);
        if (res.second - res.first < p2.second - p2.first) {
          res = p2;
        }
      }
    }
    return s.substr(res.first, res.second - res.first + 1);
  }

  pair<int, int> expand(string& s, int l, int r) {
    while (l >= 0 && r < s.size()) {
      if (s[l] != s[r]) break;
      l--;
      r++;
    }
    return {l + 1, r - 1};
  }
};