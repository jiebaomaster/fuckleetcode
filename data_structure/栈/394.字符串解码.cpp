/**
 * https://leetcode-cn.com/problems/decode-string/
 * 方法一：递归
 */
class Solution {
 public:
  string decodeString(string s) {
    int i = 0;
    return doDecode(s, i);
  }
  // 解析字符串 s[i...]，这里 i 是引用，用来在递归底层影响上层
  // 只处理一层括号，括号内部的字符串递归处理
  string doDecode(string &s, int &i) {
    string buf;
    while (i < s.size()) {
      if (isdigit(s[i])) {  // 数字，开始处理括号
        int time = 0;
        while (isdigit(s[i])) {  // 生成数字
          time = time * 10 + (s[i++] - '0');
        }
        // 此时 s[i] 指向 [，后移一位
        i++;
        // 递归解析括号内的字符串
        string t = doDecode(s, i);
        while (time--) {  // 括号内的字符串重复 time 次
          buf += t;
        }
      } else if (s[i] == ']') {  // 右括号，返回当前已解析的字符串
        i++;                     // i要后移，确保上层从 ] 之后开始
        break;
      } else {  // 字母，直接加入 buf
        buf.push_back(s[i++]);
      }
    }
    return buf;
  }
};

/**
 * 方法二：用栈存储括号关系，遇到右括号时开始处理一层括号重复
 * 这样每次处理括号都是最底层
 */
class Solution1 {
 public:
  string decodeString(string s) {
    vector<string> stk;
    int i = 0;
    while (i < s.size()) {
      if (isdigit(s[i])) {  // 数字，提取出数字入栈
        string time;
        while (isdigit(s[i])) {
          time += s[i++];
        }
        stk.push_back(time);
        // 当前 s[i] 为 [，入栈，作为 ] 的停止标志
        stk.push_back(string(1, s[i++]));
      } else if (isalpha(s[i])) {  // 字母，直接入栈
        stk.push_back(string(1, s[i++]));
      } else {  // 右括号，开始处理一次括号处理
        i++;
        // 提取栈中的字符串，直到 [ 停止，即为需要重复的词符串
        string buf;
        while (stk.back() != "[") {
          buf = stk.back() + buf;
          stk.pop_back();
        }
        // 当前 s[i] 为 [，弹出
        stk.pop_back();
        // 当前 s[i] 为 重复次数，弹出
        string timeStr = stk.back();
        stk.pop_back();
        // 将次数转化为数字
        int time = 0;
        int j = 0;
        while (j < timeStr.size()) {
          time = time * 10 + (timeStr[j++] - '0');
        }
        // 需要重复的词符串重新入栈，且入栈 time 次
        while (time--) {
          stk.push_back(buf);
        }
      }
    }
    // 此时栈中的所有字符串拼接起来就是结果
    string res;
    for (int i = 0; i < stk.size(); i++) {
      res += stk[i];
    }
    return res;
  }
};