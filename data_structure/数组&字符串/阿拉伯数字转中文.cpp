/**
 * https://www.nowcoder.com/practice/6eec992558164276a51d86d71678b300
 * https://blog.csdn.net/weixin_44370689/article/details/123108658?spm=1001.2014.3001.5502
 * 
 * 将一个数字按中文的数字读法转化为中文字符串
 * 中文的数字读法是从左往右的，所以转化时最好按照从左往右的顺序遍历数字的每一位
 */
class Solution {
 public:
  string num2cn(int n) {
    if (n == 0) return "零";
    // 数字
    vector<string> nums = {"零", "一", "二", "三", "四",
                           "五", "六", "七", "八", "九"};
    // 单位，个位的单位为空，即个位的单位不输出
    vector<string> units = {"", "十", "百", "千", "万", "十",
                            "百", "千", "亿", "十", "百", "千"};
    bool isNagitive = false;
    if (n < 0) {
      isNagitive = true;
      n *= -1;
    }

    string target = to_string(n);
    int len = target.size();

    string res;
    int pre = -1; // 当前位的前一位数字
    // 按 从左往右 的顺序遍历数字的每一位
    for (int i = 0; i < len; i++) {
      int t = target[i] - '0';
      if (t) { // 只有当前位不为 0 时，才输出数字
        if (pre == 0) { // 高位 0 的后面有不为 0 的数字，打印一个 零 填充高位
          res += nums[0];
        }
        res += nums[t];
      }
      // 拼接数字后面的单位
      // 1. 当前位不为 0，需要拼接单位
      // 2.1 当前单位是万、亿时，即使是 0 也要拼接 101234，读作 十万零一千二百三十四
      // 2.2 但是 亿、万级别的数为 0 时，不用拼接单位 万、亿，100000007，读作 一亿零七，而不是 一亿万零七
      if (t || ((len - i) % 4 == 1 && res.substr(res.size() - 3) != "亿")) {
        res += units[len - i - 1];
      }
      pre = t;
      n /= 10;
    }
    // 对于最后得到的数，处理十位，如 15 读作 “十五” 而不是 “一十五”
    // 注意汉字在 string 中是三个字节
    if (res.substr(0, 3) == "一" && res.substr(3, 3) == "十") {
      res = res.substr(3);
    }

    // 处理正负数
    if (isNagitive)
      res = "负" + res;
    return res;
  }
};