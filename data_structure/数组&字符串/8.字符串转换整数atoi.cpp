/**
 * https://leetcode.cn/problems/string-to-integer-atoi/
 */
class Solution {
 public:
  int myAtoi(string s) {
    enum states { pre, num, end };
    states state = pre;
    int isNagitive = false;
    int cur = 0;
    bool got = false;
    for (int i = 0; i < s.size(); i++) {
      char c = s[i];
      switch (state) {
        case pre: // 前序处理
          if (c == ' ') { // 跳过空格
            continue;
          } else if (c == '-' || c == '+') { // 处理正负号
            isNagitive = c == '-';
            state = num;
          } else if (c >= '0' && c <= '9') { // 遇到数字，进入数字处理
            state = num;
            cur = cur * 10 + c - '0';
          } else { // 其余字符，直接返回
            state = end;
          }
          break;
        case num: // 处理数字
          if (c >= '0' && c <= '9') { // 累加数字
            // 越界的直接返回截断
            if (cur > (INT_MAX - c + '0') / 10) {
              return isNagitive ? INT_MIN : INT_MAX;
            }
            cur = cur * 10 + (c - '0');
          } else { // 其余字符，直接返回
            state = end;
          }
          break;
        default: // end
          got = true;
      }
      if(got) break;
    }
    // 最后一个字符是数字的，从这里返回
    return isNagitive ? -1 * cur : cur;
  }
};

/**
 * 不使用转态机的写法
 */
class Solution {
 public:
  int myAtoi(string s) {
    int i = 0;
    int n = s.size();
    // 1. 跳过空格
    while (i < n && s[i] == ' ') i++;
    // 2. 处理正负号
    bool isNag = false;
    if (s[i] == '-') {
      isNag = true;
      i++;
    } else if (s[i] == '+')
      i++;
    // 3. 处理数字部分
    int cur = 0;
    while (i < n) {
      if (!isdigit(s[i])) { // 遇到非数字就退出
        break;
      }
      if (cur > (INT_MAX - (s[i] - '0')) / 10) { // 越界的直接返回截断
        return isNag ? INT_MIN : INT_MAX;
      }
      cur = cur * 10 + (s[i] - '0');
      i++;
    }
    return isNag ? -1 * cur : cur;
  }
};