/**
 * https://leetcode.cn/problems/sum-of-subarray-minimums/
 * arr 有一系列连续子数组，求所有子数组的最小值之和
 * 对于每一个元素 x，可以让它作为最小值的那些子数组必定在这样的区间 (a,b) 内，
 * 其中 a 为 x 左边第一个小于等于它的值的位置，b 为 x 右边第一个小于它的值的位置。
 * 类似于第 84 题
 * 
 * 在可以以 arr[x] 作为子树组最小值的区间 [a,b] 中，某一个包含 x 的子数组为 [l, r]
 * 则 l 可取 [a, x]，r 可取 [x, r]，
 * 故这样的子数组共有 (x - l + 1) * (r - x + 1) 个
 * 
 */
class Solution {
 public:
  int sumSubarrayMins(vector<int>& arr) {
    arr.push_back(0);
    // 递增栈，找栈顶右边第一个更小数，此时栈顶的下一个就是栈顶的左边第一个更小数
    stack<int> st; 
    long res = 0;
    for (int i = 0; i < arr.size(); i++) {
      while (!st.empty() && arr[st.top()] > arr[i]) {
        int x = st.top();
        st.pop();
        int l = st.empty() ? 0 : st.top() + 1;
        int r = i - 1;
        // 以 arr[x] 作为最小值的子数组个数
        long times = (x - l + 1) * (r - x + 1);
        res += arr[x] * times;
      }
      st.push(i);
    }

    return res % (1000000000 + 7);
  }
};