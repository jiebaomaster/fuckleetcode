/**
 * https://leetcode-cn.com/problems/palindrome-number/
 *
 * 方法一：将数字转化为字符串，判断字符串是否是回文
 *
 */
class Solution {
 public:
  bool isPalindrome(int x) {
    string s;
    if (x < 0) return false;
    while (x) {
      s.push_back(x % 10);
      x /= 10;
    }
    int i = 0;
    int j = s.size() - 1;
    while (i < j) {
      if (s[i] != s[j]) return false;
      i++;
      j--;
    }
    return true;
  }
};

/**
 * 方法二：构造翻转的数字
 * int 翻转后可能会溢出，需要用 long 保存翻转后的数
 * 当然，回文数显然是不可能溢出的，可以用 try 捕捉溢出错误，溢出的话就返回 false
 */
class Solution1 {
 public:
  bool isPalindrome(int x) {
    if (x < 0) return false;
    long xx = x;
    long rx = 0;
    while (x) {
      // x 的地位是 rx 的高位
      rx = rx * 10 + x % 10;
      x /= 10;
    }
    return rx == xx;
  }
};

/**
 * 方法三：构造翻转一半的数字
 * 将 n 位的回文数分为前后两部分，其中低 n/2 位翻转之后必等于高 n/2 位
 * 如 1221，低 n/2 位为 21，翻转之后为 12，等于高 n/2 位
 */
class Solution2 {
 public:
  bool isPalindrome(int x) {
    // 特殊情况：
    // 1. 负数肯定不是回文数
    // 2. 如果数字的最后一位是 0，为了使该数字为回文，
    //    则其第一位数字也应该是 0，只有 0 满足这一属性
    if (x < 0 || (x != 0 && x % 10 == 0)) return false;
    int rx = 0;
    // rx < x 时必定翻转了一半
    while (rx < x) {
      rx = rx * 10 + x % 10;
      x /= 10;
    }
    // 当数字长度为奇数时，通过 rx/10 去除处于中位的数字。
    // 例如，当输入为 12321 时，在 while 循环的末尾我们可以得到 x = 12，rx = 123，
    // 由于处于中位的数字不影响回文（它总是与自己相等），所以我们可以简单地将其去除。
    return rx == x || rx / 10 == x;
  }
};