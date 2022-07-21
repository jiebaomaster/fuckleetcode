/**
 * https://leetcode-cn.com/problems/implement-rand10-using-rand7/
 * 采用拒绝抽样法，先随机选到一个符合要求的数，再在这个数上取新的随机数
 * 
 * (randX() - 1)*Y + randY() 可以等概率的生成 [1, X * Y] 范围的随机数
 * 例如：
 * rand7() 能等概率生成 1~7；
 * => rand7()-1 能等概率生成 0~6； 
 * => (rand7() - 1) * 7 能等概率生成 {0, 7, 14, 21, 28, 35, 42}；
 * => (rand7() - 1) * 7 + rand7() 能等概率生成 1~49
 * 
 */
class Solution {
 public:
  int rand10() {
    int i, j, t;
    do {
      i = rand7();
      j = rand7();
      t = i + (j - 1) * 7;
    } while (t > 40); // 拒绝大于40的随机数，返回的随机数是 [1,40] 内等概率的
    // 采用拒绝抽样法，生成的 [1,40] 内的随机数
    // 再对结果 %10 + 1 就可以得到 [1,10] 内的随机数
    return 1 + t % 10;
  }
};

/**
 * 扩展：rand3 构造 rand18
 * 先由 (rand3()-1)*3+rand3() 构造 rand9
 * 再由 (rand3()-1)*9+rand9() 构造 rand27
 * 最后由 rand27 拒绝采样得 rand18
 */