class FreqStack {
    // 记录最大的元素出现次数，以快速出栈
    int maxFreq = 0;
    // 值-》出现次数，使 push 时能快速获取并更新元素的出现次数，
    unordered_map<int, int> val_freq{};
    /**
     * freq_vals 的结构，map 出现了 key 次的元素，
     * 出现了 x 次的元素一定出现了 x-i 次，stack保证出栈时先进后出
     *  key  stack
     *  3:   {1,}
     *  2:   {1,2}
     *  1:   {1,2,3}
     * 这种情况下，1出现了3次，2处理2次，3出现了1次 
     */
    unordered_map<int, stack<int>> freq_vals{}; 
public:
    FreqStack() {}
    
    void push(int val) {
        int freq = ++val_freq[val]; // 递增元素的出现次数
        freq_vals[freq].push(val); // 入到递增 freq 后的栈，不从栈上删除原先的元素，
                                   // 保证出现了 x 次的元素一定出现了 x-i 次
        maxFreq = max(maxFreq, freq); // 有可能要更新最大freq
    }
    
    int pop() {
        int top = freq_vals[maxFreq].top(); // 返回最大 freq 的栈顶
        freq_vals[maxFreq].pop();
        val_freq[top]--; // 递减元素的出现次数
        if(freq_vals[maxFreq].size() == 0) // 最大 freq 栈的元素全部都出栈了，递减最大 freq
            maxFreq--;

        return top;
    }
};

/**
 * https://leetcode-cn.com/problems/maximum-frequency-stack/
 * https://mp.weixin.qq.com/s/oXv03m1J8TwtHwMJEZ1ApQ
 * 
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */