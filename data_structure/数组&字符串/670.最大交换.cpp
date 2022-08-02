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

/**
 * 可得的最大的数是每一位从大到小排列的，从最大的数出发，看当前数和最大数的差距
 * 对比排序前后字符串，找出第一个不一样的，这两个就是要交换的数，
 * 然后从排序前的那个开始往后面找出与排序后的数一样的，
 *   源数据 3979
 *  排序 => 9973
 *  第一个不同为第一位，则第一位应该是 9，在源数据中从后往前找第一个 9，并与第一位交换
 *  交换 => 9973
 */
class Solution {
 public:
  int maximumSwap(int num) {
    vector<int> str;
    int num_pre = num;
    while (num) {
      str.push_back(num % 10);
      num /= 10;
    }
    vector<int> maxStr(str.begin(), str.end());
    sort(maxStr.begin(), maxStr.end());
    int n = str.size();
    for (int i = n - 1; i >= 0; i--) {
      if (str[i] != maxStr[i]) {
        for (int j = 0; j < i; j++) {
          if (maxStr[i] == str[j]) {
            swap(str[j], str[i]);

            int res = 0;
            for (int k = n - 1; k >= 0; k--) res = res * 10 + str[k];
            return res;
          }
        }
      }
    }
    return num_pre;
  }
};