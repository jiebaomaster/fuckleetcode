class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> s; // 单调栈，栈底到栈顶递减
        // 题目要求循环遍历，可以看做nums的后面又接了一个nums [nums，nums]
        // 实际操作时不必真的复制nums，在获取nums的元素时下标取余即可
        for(int i = 0; i < n * 2; i++) {
            while (!s.empty() && nums[s.top()] < nums[i % n]) {
                res[s.top()] = nums[i % n];
                s.pop();
            }
            s.push(i % n);
        }

        return res;
    }
};

/**
 * https://leetcode-cn.com/problems/next-greater-element-ii/
 * https://labuladong.gitbook.io/algo/mu-lu-ye-1/mu-lu-ye-3/dan-tiao-zhan#ru-he-chu-li-huan-xing-shu-zu
 */