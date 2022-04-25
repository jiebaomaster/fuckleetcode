/**
 * https://www.nowcoder.com/practice/c5db069fd9d64e6e9cf5fd68860abcdd?tpId=196&tqId=40394&rp=1&ru=/exam/oj&qru=/exam/oj&sourceUrl=%2Fexam%2Foj%3Ftab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D196&difficulty=undefined&judgeStatus=undefined&tags=&title=
 * https://mp.weixin.qq.com/s/XcKQwnwCh5nZsz-DLHJwzQ
 * 思路基本和普通的十进制字符串加法一样，只是需要添加一步进制转换
 */
class Solution {
 public:
  string thirtysixAdd(string A, string B) {
    int p = A.size() - 1;
    int q = B.size() - 1;
    string res;
    int carry = 0;
    while (p >= 0 || q >= 0 || carry) {
      int t = carry;
      if (p >= 0) t += toVal(A[p--]);
      if (q >= 0) t += toVal(B[q--]);
      res += toChar(t % 36);
      carry = t / 36;
    }
    reverse(res.begin(), res.end());
    return res;
  }
  // 一个字符的进制转换，36 进制字符转十进制数
  int toVal(char c) {
    if (isdigit(c))
      return c - '0';
    else
      return c - 'a' + 10;
  }
  // 十进制树转 36 进制字符
  char toChar(int v) {
    if (v < 10)
      return v + '0';
    else
      return v - 10 + 'a';
  }
};