/**
 * https://leetcode-cn.com/problems/gou-jian-cheng-ji-shu-zu-lcof/
 */
class Solution {
 public:
  vector<int> constructArr(vector<int>& a) {
    if (a.size() == 0) return {};
    int len = a.size();
    vector<int> prefix(len); // 计算 [0...i-1] 的乘积 
    vector<int> postfix(len); // 计算 [i+1...len-1] 的乘积
    // 结果为 [0...i-1]*[i+1...len-1] = prefix[i]*postfix[i]
    vector<int> res(len);
    prefix[0] = 1;
    postfix[len - 1] = 1;
    for (int i = 1; i < len; i++) {
      prefix[i] = prefix[i - 1] * a[i - 1];
      postfix[len - i - 1] = postfix[len - i] * a[len - i];
    }
    for (int i = 0; i < len; i++) {
      res[i] = prefix[i] * postfix[i];
    }
    return res;
  }
};

/**
 * 优化上述方法的空间复杂度，不需要额外空间记录前后缀
 * https://leetcode-cn.com/problems/gou-jian-cheng-ji-shu-zu-lcof/solution/mian-shi-ti-66-gou-jian-cheng-ji-shu-zu-biao-ge-fe/
 */
class Solution1 {
 public:
  vector<int> constructArr(vector<int>& a) {
    if (a.size() == 0) return {};
    int len = a.size();
    vector<int> res(len);
    res[0] = 1;
    // 将前缀直接保存在 res
    for (int i = 1; i < len; i++) {
      res[i] = a[i - 1] * res[i - 1];
    }
    int tmp = 1; // 记录后缀
    for (int i = len - 2; i >= 0; i--) {
      tmp *= a[i + 1]; // 更新后缀
      res[i] *= tmp; // 将原本保存的前缀乘以后缀
    }
    return res;
  }
};