/**
 * https://www.nowcoder.com/questionTerminal/edfe05a1d45c4ea89101d936cac32469?commentTags=Java
 * https://mp.weixin.qq.com/s/rMsbcUf9ZPhvfRoyZGW6HA
 * 在一个数组中，每一个数左边比当前数小的数累加起来，叫做这个数组的小和。求一个数组的小和。
 * 
 * 从小到大归并排序
 * 当左半边的 xl 被选中时，右半边剩余的所有元素都大于等于 xl，
 * 则 xl 和右半边剩余的所有元素构成小和 xl * (j - q + 1)
 */
#include <stdio.h>

#include <iostream>

using namespace std;
int arr[100010];
int buf[100010];
long long res;
void mergeSort(int i, int j) {
  if (i >= j) return;
  int mid = i + (j - i) / 2;
  mergeSort(i, mid);
  mergeSort(mid + 1, j);

  int p = i, q = mid + 1;
  int k = i;
  while (p <= mid && q <= j) {
    if (arr[p] <= arr[q]) {
      buf[k++] = arr[p];
      res += arr[p] * (j - q + 1);
      p++;
    } else {
      buf[k++] = arr[q++];
    }
  }
  while (p <= mid) buf[k++] = arr[p++];
  while (q <= j) buf[k++] = arr[q++];
  while (i <= j) {
    arr[i] = buf[i];
    i++;
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &(arr[i]));
  res = 0;
  mergeSort(0, n - 1);
  printf("%lld\n", res);
}