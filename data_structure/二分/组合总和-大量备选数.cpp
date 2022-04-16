/**
 * 从 1～k 之间选择 n 个不相同的数，使得这 n 个数的和为 x
 * 可能会有多种选择，只需返回其中一个
 * 这题的 k 和 x 非常大，所以不能套用回溯和背包
 * 
 * 注意到：如果 x 在 [sum(1,n), sum(k-n+1,k)] 之间，则必有可选的组合
 * 我们可以从大到小一个一个选出所有的数
 * 选第一个数：
 *  若 t1 是 [1,k] 之间满足 sum(t1-n+1,t1) >= x 的第一个数，
 *  则可以选择 t1 作为最大的被选数
 * 选第二个数：
 *  若 t2 是 [1,t1-1] 之间满足 sum(t2-n+1,t2) >= x-t1 的第一个数，
 *  则可以选择 t2 作为第二大的被选数
 * ...
 * 选出所有的 n 个数
 * 注意到 sum 是一个关于 t 的递增函数，所以每次选择可以使用二分法加速
 */
#include <stdio.h>

#include <vector>
using namespace std;

// 计算 [t-n+1,t] 之间所有元素的累加和
inline unsigned long long sum(unsigned long long t, unsigned long long n) {
  return ((t - n + 1 + t) * n) / 2;
}
/**
 * 从 [l,r) 之间找第一个 sum(t-n+1,t) >= target 的 t
 * @param n 用于计算累加和的项数
 */
unsigned long long find(unsigned long long target, unsigned long long n,
                        unsigned long long l, unsigned long long r) {
  while (l < r) {
    unsigned long long mid = l + (r - l) / 2;
    if (sum(mid, n) < target)
      l = mid + 1;
    else
      r = mid;
  }
  return r;
}

int main() {
  unsigned long long n, k, x;

  while (scanf("%llu %llu %llu", &n, &k, &x) != EOF) {
    vector<unsigned long long> res;
    bool get = true;
    while (n) {
      // 确定当前位置的选择
      int t = find(x, n, n, k + 1);
      if (t == k + 1) {  // 不存在res，失败
        get = false;
        break; 
      }
      res.push_back(t);
      x -= t;     // 更新剩余 target
      k = t - 1;  // 更新选择最大值
      n--;        // 更新选择数的数量
    }
    if (!get) {
      printf("-1\n");
      continue;
    }
    // 输出结果
    for (int i = 0; i < res.size(); ++i) {
      if (i == 0)
        printf("%llu", res[0]);
      else
        printf(" %llu", res[i]);
    }
    printf("\n");
  }
}
