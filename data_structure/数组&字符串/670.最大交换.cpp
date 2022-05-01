/**
 * https://leetcode-cn.com/problems/maximum-swap/
 * 至多可以交换一次数字中的任意两位，返回最大的数
 * 要使返回的数更大，尽可能的让最大的数在最高位，
 */
class Solution {
 public:
  int maximumSwap(int num) {
    // 1. 将数字转化成字符串
    string n;
    while (num) {
      n += '0' + num % 10;
      num /= 10;
    }
    int len = n.size();
    // 2. 求对于第i位，在1～i位之间的最大值，前缀最大
    vector<int> rightMax(len);
    rightMax[0] = 0;
    for (int i = 1; i < len; i++) {
      rightMax[i] = n[i] <= n[rightMax[i - 1]] ? rightMax[i - 1] : i;
    }
    // 3. 第一个前缀最大不是本身的，就是需要调换的位，将其与前缀最大调换
    for (int i = len - 1; i >= 0; i--) {
      if (rightMax[i] != i && n[i] != n[rightMax[i]]) {
        swap(n[rightMax[i]], n[i]);
        break;
      }
    }
    // 4. 结果字符串转数字
    int res = 0;
    while (!n.empty()) {
      res = res * 10 + n.back() - '0';
      n.pop_back();
    }
    return res;
  }
};