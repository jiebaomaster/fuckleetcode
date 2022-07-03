/**
 * https://leetcode.cn/problems/maximum-xor-of-two-numbers-in-an-array/
 * 方法一：hash
 * https://leetcode.cn/problems/maximum-xor-of-two-numbers-in-an-array/solution/li-yong-yi-huo-yun-suan-de-xing-zhi-tan-xin-suan-f/
 */
class Solution {
 public:
  int findMaximumXOR(vector<int>& nums) {
    int mask = 0;
    int res = 0;

    // 先确定高位，再确定低位（有点贪心算法的意思），才能保证这道题的最大性质
    // 一位接着一位去确定这个数位的大小
    // 利用性质： a ^ b = c ，则 a ^ c = b，且 b ^ c = a
    for (int i = 30; i >= 0; i--) {
      mask = mask | (1 << i);

      unordered_set<int> s;
      for (auto n : nums) {
        s.insert(n & mask);
      }

      // 假定第 n 位为 1 ，前 n-1 位 res 为之前迭代求得
      // 如果 set 中存在 k 使得 k = t ^ n，则有 n ^ k = t，所以这一位可以是 1
      int t = res | (1 << i);
      for (auto n : s) {
        if (s.count(t ^ n)) {
          res = t;
          break;
        }
      }
    }
    return res;
  }
};

/**
 * 方法二：前缀树剪枝
 * https://leetcode.cn/problems/maximum-xor-of-two-numbers-in-an-array/solution/python3-qiao-miao-li-yong-qian-zhui-shu-0alcy/
 * 其实每个数字还是都要和其他数字做异或，不过利用了前缀树和贪心思想，每一步都挑一个最大的值，把其他路径都剪枝掉了
 */
class Solution {
  struct TrieNode {
    int times;
    TrieNode* children[2]; // 二叉，二进制位为 0 或 1
    TrieNode() : times(0) {
      children[0] = nullptr;
      children[1] = nullptr;
    }
  };
  class Trie {
    TrieNode root;

   public:
    void add(int val) { // 添加数字到前缀树
      auto n = &root;
      for (int i = 30; i >= 0; i--) {
        int t = (val >> i) & 1; // 取第 i 个二进制数
        if (!n->children[t]) {
          n->children[t] = new TrieNode();
        }
        n = n->children[t];
        n->times++;
      }
    }

    /**
     * 从前缀树里找异或最大值
     * 将每一个二进制位，在对应的层中找到一个异或的最大值，也就是：如果是1，找0的那条路径，如果是0，找1的那条路径。
     * 贪心的思想，从最高位找到最低位，尽量保证每一位都是 1
     */
    int find(int val) {
      int res = 0;
      auto n = &root;
      for (int i = 30; i >= 0; i--) {
        int t = (val >> i) & 1;
        if (n->children[!t]) {
          n = n->children[!t];
          res |= 1 << i;
        } else {
          n = n->children[t];
        }
      }
      return res;
    }
  };

 public:
  int findMaximumXOR(vector<int>& nums) {
    Trie t;
    for (auto n : nums) t.add(n); // 建立前缀树

    int res = 0;
    for (auto n : nums) { // 从前缀树里直接找到每一个数的异或最大值
      res = max(res, t.find(n));
    }
    return res;
  }
};