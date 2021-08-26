class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0); // 初始化为 0
        stack<int> s; // 单调栈，栈底到栈顶递减
        for(int i = 0; i < temperatures.size(); i++) { // 扫描整个列表，每个元素都入栈一次
            while(!s.empty() && temperatures[s.top()] < temperatures[i]) {
                // 如果列表元素大于栈顶，循环出栈，保持单调性
                int tmp = s.top();
                s.pop();
                // 每次出栈表示找到了一个元素的“下一个最大的”
                res[tmp] = i - tmp;
            }
            s.push(i); // 当前列表元素出栈
        }

        return res;
    }
};

/**
 * https://leetcode-cn.com/problems/daily-temperatures/
 * https://labuladong.gitbook.io/algo/mu-lu-ye-1/mu-lu-ye-3/dan-tiao-zhan#wen-ti-bian-xing
 */