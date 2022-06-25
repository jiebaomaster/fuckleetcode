/**
 * https://leetcode.cn/problems/integer-to-english-words/
 * 类似于 阿拉伯数字转中文，
 * 三个一组，一组不为 0 时需要输出组单位 dd，
 * 组内：
 *    百位后面要加上 Hundred
 *    十位是 1 要特殊处理，其他情况简单遵循 十位+个位
 */
class Solution {
 public:
  const vector<string> dx = {
      "",      "One ", "Two ",   "Three ", "Four ",
      "Five ", "Six ", "Seven ", "Eight ", "Nine ",
  };
  const vector<string> d1x = {"Ten ",      "Eleven ",  "Twelve ",  "Thirteen ",
                              "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ",
                              "Eighteen ", "Nineteen "};
  const vector<string> dx0 = {"",        "",       "Twenty ", "Thirty ",
                              "Forty ",  "Fifty ", "Sixty ",  "Seventy ",
                              "Eighty ", "Ninety "};
  const vector<string> dd = {"", "Thousand ", "Million ", "Billion "};
  const string d100 = "Hundred ";
  string numberToWords(int num) {
    string res;
    int sectionCnt = 0;
    while (num) { // 三位一组，每次处理一组
      int t = num % 1000;
      string section;
      if (t > 99) { // 特殊处理百位
        section = dx[t / 100] + d100;
        t = t % 100;
      }
      if (t / 10 == 1) { // 特殊处理 十 位是 1 的情况
        section += d1x[t % 10];
      } else { // 十位 + 个位
        section += dx0[t / 10] + dx[t % 10];
      }
      if (num % 1000) // 这一组非 0，需要输出组单位
        section += dd[sectionCnt];

      sectionCnt++;
      res = section + res;
      num /= 1000;
    }
    if (!res.empty()) // 去除最后的空格
      res.resize(res.size() - 1);
    else
      return "Zero";
    return res;
  }
};