/**
 * https://leetcode-cn.com/problems/validate-ip-address/
 * 复杂的字符串处理可以使用状态机
 */
class Solution {
 public:
  string validIPAddress(string queryIP) {
    // 遍历两次，依次判断是否是 IPv4 和 IPv6
    if (isIPv4(queryIP))
      return "IPv4";
    else if (isIPv6(queryIP))
      return "IPv6";
    else
      return "Neither";
  }
  bool isIPv4(string &s) {
    // 状态机
    enum state { 
      n_number, // 期望数字
      n_dot, // 期望 .
      n_end // 期望结束
    };
    enum state cur = n_number;
    int i = 0;
    int dotCnt = 0;
    int t;
    while (1) {
      switch (cur) {
        case n_number:
          if (!isdigit(s[i])) return false;
          if (s[i] == '0') { // 不能有前导 0，读入一个 0 就进行状态跳转
            i++;
            goto next;
          }
          t = numbertify_255(s, i);
          if (t > 255) return false;
        next: // 根据当前已读如的 . 的个数进行状态跳转
          if (dotCnt == 3)
            cur = n_end;
          else
            cur = n_dot;
          break;
        case n_dot:
          if (s[i] != '.') return false;
          dotCnt++; // 更新 . 的个数
          i++;
          cur = n_number;
          break;
        case n_end:
          return i == s.size();
      }
    }
  }
  bool isIPv6(string &s) {
    enum state { 
      n_number, // 期望数字 
      n_colon, // 期望 :
      n_end  // 期望结束
    };
    enum state cur = n_number;
    int i = 0;
    int colonCnt = 0;
    int pre;
    int t;
    while (1) {
      switch (cur) {
        case n_number:
          pre = i;
          // IPv6 只需满足是 16 进制数字即可
          while (i < s.size() && is16digit(s[i])) i++;
          // 每个数字段的长度满足 1 <= len <= 4
          if (i == pre || i - pre > 4) return false;

          if (colonCnt == 7)
            cur = n_end;
          else
            cur = n_colon;
          break;
        case n_colon: // 根据当前已读如的 : 的个数进行状态跳转
          if (s[i] != ':') return false;
          colonCnt++;
          i++;
          cur = n_number;
          break;
        case n_end:
          return i == s.size();
      }
    }
  }
  // 判断是否是 16 进制数的字符
  bool is16digit(char c) {
    return isdigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
  }
  // 从字符串中提取整数，大于 255 时退出
  int numbertify_255(string &s, int &i) {
    int tmp = 0;
    while (isdigit(s[i])) {
      tmp = tmp * 10 + (s[i++] - '0');
      if (tmp > 255) break;
    }
    return tmp;
  }
};

class Solution {
 public:
  string validIPAddress(string queryIP) {
    if (isIPv4(queryIP))
      return "IPv4";
    else if (isIPv6(queryIP))
      return "IPv6";
    return "Neither";
  }

  bool isIPv4(string &ip) {
    int dotCnt = 0;
    int l = 0;
    if (ip.back() == '.') return false;
    for (int i = 0; i < ip.size(); i++) {
      if (ip[i] == '.' || i == ip.size() - 1) {
        if (i == ip.size() - 1) i++;
        dotCnt++;
        if (ip[l] == '.' || i - l > 3) return false;
        if (ip[l] == '0' && l + 1 < i) return false;
        int cur = 0;
        while (l < i) {
          if (!isdigit(ip[l])) return false;
          cur = cur * 10 + (ip[l] - '0');
          l++;
        }

        if (cur > 255) return false;

        l = i + 1;
      }
    }
    return dotCnt == 4;
  }

  bool isIPv6(string &ip) {
    int cnt = 0;
    int l = 0;
    if (ip.back() == ':') return false;
    for (int i = 0; i < ip.size(); i++) {
      if (ip[i] == ':' || i == ip.size() - 1) {
        if (i == ip.size() - 1) i++;

        cnt++;
        if (ip[l] == ':' || i - l > 4) return false;
        while (l < i) {
          if (!isdigit(ip[l]) && !((ip[l] >= 'a' && ip[l] <= 'f') ||
                                   (ip[l] >= 'A' && ip[l] <= 'F')))
            return false;
          l++;
        }

        l = i + 1;
      }
    }
    return cnt == 8;
  }
};