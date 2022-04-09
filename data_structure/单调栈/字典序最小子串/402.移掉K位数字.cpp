/**
 * https://leetcode-cn.com/problems/remove-k-digits/
 * https://leetcode-cn.com/problems/remove-duplicate-letters/solution/yi-zhao-chi-bian-li-kou-si-dao-ti-ma-ma-zai-ye-b-4/
 * 
 * 移除某个数中的 k 位数字，使得剩下的数字最小，其实就是在求一个字典序最小的子串
 * 由单调栈保证字典序最小，附加的出栈条件保证只移除 k 个数字
 */
class Solution {
 public:
  string removeKdigits(string num, int k) {
    if (num.size() == 0 || num.size() == k) return "0";
    // 两个相同位数的数字大小关系取决于第一个不同的数的大小。第一个不同的数小的那个数字更小。
    // 单调递增栈尽量保留最小的数字，注意保留的顺序是相反的
    stack<char> s;  
    int i = 0;
    while (i < num.size()) {
      // 每次出栈代表有一个数字被移除，最多移除 k 个数字
      while (!s.empty() && k > 0 && num[i] < s.top()) {
        s.pop();
        k--;
      }
      s.push(num[i]);
      i++;
    }
    string res;
    while (!s.empty()) {
      // k > 0 代表移除的数还不够多，此时要移除栈顶的数凑数，因为栈顶的数更大
      if (k > 0) {
        k--;
        s.pop();
        continue;
      }
      // 将栈中的数逆序拼接成字符串
      res = string(1, s.top()) + res;
      s.pop();
    }

    // 数字要去除前导 0，空串要返回0
    auto pos = res.find_first_not_of('0');
    if (pos == string::npos)
      return "0";
    else {
      string ss = res.substr(pos);
      return ss.size() == 0 ? "0" : ss;
    }
  }
};

/**
 * 用 vector 代替 stack，加速字符串拼接
 */
class Solution {
public:
 string removeKdigits(string num, int k) {
   vector<char> stk; // 用 vector 代替 stack，加速字符串拼接
   // 单调栈保持字典序最小的数
   for (int i = 0; i < num.size(); i++) {
     while (!stk.empty() && k > 0 && num[i] < stk.back()) {
       stk.pop_back();
       k--;
     }
     stk.push_back(num[i]);
   }

   while (!stk.empty() && k--) {
     stk.pop_back();
   }
   string res;
   bool firstNotZero = false;
   for (char c : stk) {
     // 去除前导 0
     if (!firstNotZero && c == '0') continue;
     firstNotZero = true;
     res += string(1, c);
   }
   if (!res.size()) return "0";
   return res;
 }
};