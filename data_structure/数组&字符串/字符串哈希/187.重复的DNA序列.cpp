/**
 * https://leetcode.cn/problems/repeated-dna-sequences/
 * 方法一：map 默认哈希string，滑动窗口
 */
class Solution {
 public:
  vector<string> findRepeatedDnaSequences(string s) {
    vector<string> res;

    unordered_map<string, int> subs;
    for (int i = 0; i + 9 < s.size(); i++) {
      auto sub = s.substr(i, 10); // 长度为 10 的子串 s[i~i+10) 
      if (subs[sub] == 1) { // 判断是否子串出现过一次
        res.push_back(sub);
      }
      subs[sub]++;
    }

    return res;
  }
};
/**
 * 方法二：利用前缀和求字符串哈希
 * https://leetcode.cn/problems/longest-duplicate-substring/solution/wei-rao-li-lun-rabin-karp-er-fen-sou-suo-3c22/
 * 
 * 上面的方法每次做字符串哈希时都遍历了一次子串，时间复杂度为 O(Cn)
 * 其中 C=10 子串长度
 * 如果要判断的子串长度比较长即 C 很大，会显著影响时间复杂度
 * 可以使用前缀优化连续字符串的哈希值计算，使得计算哈希消耗的时间为常数
 * 
 * 字符串 s[0,n) 的哈希可由质数累乘法得到 取质数 P
 * hash[0, n-1] = s[0]*P^(n-1) + s[1]*P^(n-2) + ... + s[n-2]*P^1 + s[n-1]*P^0
 * 
 * 则子串 s[0, j] 的哈希值为
 * hash[0,j] =   s[0]*P^(j) + s[1]*P^(j-1) + ... + s[j-1]*P^1 + s[j]*P^0
 *           =   s[0]*P^(j)   + s[1]*P^(j-1) + ... + s[i-2]*P^(j-i+2) + s[i-1]*P^(j-i+1) + s[i]*P^(j-i) + s[i+1]*P^(j-i-1) +  ... + s[j-1]*P^1 + s[j]*P^0
 * 则子串 s[0, i-1] 的哈希值为
 * hash[0,i-1] = s[0]*P^(i-1) + s[1]*P^(i-2) + ... + s[i-2]*P^1       + s[i-1]*P^0
 * 
 * 则子串 s[i, j] 的哈希值为                                                      hash[i,j] = s[i]*P^(j-i) + s[i+1]*P^(j-i-1) + ... + s[j-1]*P^1 + s[j]*P^0
 *                                                                                       = h[0,j] - h[0,i-1]*P(j-i+1)
 *
 */
class Solution {
 public:
  vector<string> findRepeatedDnaSequences(string s) {
    vector<string> res;
    int PRIME = 131313; // 选择的质数，决定了哈希冲突的概率
    int len = 10;
    // 用 unsigned long long 不会溢出报错，溢出时相当于取模了，带符号的类型溢出时会报错
    vector<unsigned long long> hash(s.size() + 1); // 前 i 个字符的哈希值
    vector<unsigned long long> power(s.size() + 1); // PRIME^i
    power[0] = 1;
    for (int i = 1; i <= s.size(); i++) { // 求哈希前缀
      hash[i] = hash[i - 1] * PRIME + s[i - 1];
      power[i] = PRIME * power[i - 1];
    }
    unordered_map<unsigned long long, int> subs;
    for (int j = len; j <= s.size(); j++) {
      int i = j - len + 1;
      // hash[i,j]
      auto h = hash[j] - hash[i - 1] * power[len];
      if (subs[h] == 1) {
        res.push_back(s.substr(i - 1, len));
      }
      subs[h]++;
    }

    return res;
  }
};