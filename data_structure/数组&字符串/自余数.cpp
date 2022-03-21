/**
 * sum[x] 为 x 上每一位的和
 * 若 x % sum[x] == 1 则称 x 为自余数，求 [l,r] 内的自余数的个数
 * 其中 0 <= l <= r <= 10^6 
 */
#include <math.h>
#include <stdio.h>

using namespace std;
#define MAX 1000000
int sum[MAX] = {0};

int main() {
  // 打表法，从小到大顺序执行
  // 可将 i 的位划分为 i/10 和个位 i%10
  for (int i = 0; i < MAX; i++) {
    sum[i] = sum[i / 10] + i % 10;
  }
  // 计算前缀和，即 sum[i] 表示 [0~i] 内共有几个自余数
  for (int i = 1; i < MAX; i++) {
    if (i % sum[i] == 1)
      sum[i] = sum[i - 1] + 1;
    else
      sum[i] = sum[i - 1];
  }

  int n;
  while (scanf("%d", &n) != EOF) {
    while (n--) {
      int l, r;
      scanf("%d %d", &l, &r);
      printf("%d\n", sum[r] - sum[l - 1]);
    }
  }
}