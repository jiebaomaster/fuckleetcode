/**
 * https://leetcode-cn.com/problems/candy/
 * n 个孩子站成一排，分糖果：
 *    每个孩子至少分配到 1 个糖果。
 *    相邻两个孩子评分更高的孩子会获得更多的糖果。
 * 
 * 方法一：两次遍历
 * 可以将「相邻的孩子中，评分高的孩子必须获得更多的糖果」这句话拆分为两个规则
 * 左规则，本节点比左边大时，candy[i] > candy[i-1]
 * 右规则，本节点比右边大时，candy[i] > candy[i+1]
 * 遍历两次，每个位置都取同时满足两个规则的值
 */
class Solution {
 public:
  int candy(vector<int>& ratings) {
    int n = ratings.size();
    // 求满足左规则的值
    vector<int> left(n);
    left[0] = 1;
    for (int i = 1; i < n; i++) {
      if (ratings[i] > ratings[i - 1])
        left[i] = left[i - 1] + 1;
      else
        left[i] = 1;
    }
    // 求满足右规则的值
    int right = 1;
    int res = max(right, left[n - 1]);
    for (int i = n - 2; i >= 0; i--) {
      if (ratings[i] > ratings[i + 1]) {
        right++;
      } else
        right = 1;
      res += max(right, left[i]);
    }
    return res;
  }
};

/**
 * https://leetcode-cn.com/problems/candy/solution/fen-fa-tang-guo-by-leetcode-solution-f01p/
 * 方法二：一次遍历
 * 判断当前位置所处的是递增序列还是递减序列，
 * 在递增序列中时，当前位置分配 pre+1
 * 在递减序列中时，当前位置先分配 1，且递减序列前面的所有位置分配数+1
 *    且递减序列长度和上一个递增序列等长时，需要把最近的递增序列的最后一个也算作递减序列
 */
class Solution1 {
 public:
  int candy(vector<int>& ratings) {
    int n = ratings.size();
    int ins_len = 1; // 上一个递增序列长度
    int dec_len = 0; // 当前递减序列长度
    int pre = 1; // 前一个位置的糖果数
    int res = 1;
    for (int i = 1; i < n; i++) {
      if (ratings[i] == ratings[i - 1]) {
        pre = 1;
        res += pre;
        ins_len = 1;
        dec_len = 0;
      } else if (ratings[i] > ratings[i - 1]) {  // ins
        pre++;
        res += pre;
        ins_len = pre;
        dec_len = 0;
      } else {  // des
        pre = 1;
        res += pre;
        dec_len++;
        if (dec_len == ins_len) dec_len++;
        res += dec_len - 1;
      }
    }
    return res;
  }
};

/**
 * 变体：n 个孩子站成一个圈
 * 
 * 只需要在首尾补充两个元素，首部补充原尾部元素，尾部补充原首部元素，
 * 计算方法还是一样的，只是最后求和的时候刨去添加的首尾。
 */