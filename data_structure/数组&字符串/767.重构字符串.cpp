/**
 * https://leetcode.cn/problems/reorganize-string/
 * 给定一个字符串 s ，检查是否能重新排布其中的字母，使得两相邻的字符不同
 * 
 * 判断解存在很容易，出现次数最多的字符不能超过1半[上取整]
 * 直接以最多的元素为隔板，进行分堆插入；
 * 排序源字符串，依次循环插入到隔板堆中，这样相同的元素一定在不同的桶之中。
 */
class Solution {
 public:
  string reorganizeString(string s) {
    unordered_map<char, int> ctimes;
    char maxC = s[0];
    for (char c : s) { // 统计出最多的元素
      ctimes[c]++;
      if (ctimes[maxC] < ctimes[c]) maxC = c;
    }

    if (ctimes[maxC] > (1 + s.size()) / 2) return "";

    sort(s.begin(), s.end());
    vector<string> bucket(ctimes[maxC]);
    int i = 0;
    for (char c : s) { // 插入以 maxC 分割的桶中
      if (c != maxC) {
        bucket[i] += string(1, c);
        // 每次插入不同的桶
        i++;
        i %= ctimes[maxC];
      }
    }
    string res;
    for (auto &b : bucket) { // 将每个桶以 maxC 连接
      res += string(1, maxC) + b;
    }
    return res;
  }
};