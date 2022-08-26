/**
 * 暴力解法需要以haystack的每个位置为起点开始匹配，则时间复杂度为 O(n*m)
 * 
 * 方法一：字符串哈希
 * 使用字符串哈希可以在常数时间求出子串 haystack[i, i+len) 的哈希值，判断与 needle 的哈希值是否相等，即可知道字符串是否相等
 * 时间复杂度为 O(n)
 */
class Solution {
 public:
  int strStr(string haystack, string needle) {
    if (needle.size() == 0) return 0;

    int PRIME = 131313;
    int n = haystack.size(), m = needle.size();
    if(n < m) return -1;

    vector<unsigned long long> hash_haystack(n + 1);  // 前 i 个字符的哈希值
    vector<unsigned long long> hash_needle(m + 1);  // 前 i 个字符的哈希值
    unsigned long long orderPowerM = 1; // PRIME^m
    for (int i = 1; i <= n; i++) {
      // 求 haystack 哈希前缀
      hash_haystack[i] = hash_haystack[i - 1] * PRIME + haystack[i - 1];
    }
    for (int i = 1; i <= m; i++) { // 求 needle 哈希前缀
      orderPowerM *= PRIME;
      hash_needle[i] = hash_needle[i - 1] * PRIME + needle[i - 1];
    }  

    for (int j = m; j <= n; j++) {
      int i = j - m + 1;
      // hash[i,j]
      auto h = hash_haystack[j] - hash_haystack[i - 1] * orderPowerM;
      if (h == hash_needle[m]) return i - 1;
    }
    return -1;
  }
};