class MedianFinder {
    // 小顶堆，存储流中较大的一半
    priority_queue<int, vector<int>, greater<int>> large{};
    // 大顶堆，储存流中较小的一半
    priority_queue<int> small{};
    size_t n = 0; // 记录流的数据数量
public:
    /** initialize your data structure here. */
    MedianFinder() {}
    
    void addNum(int num) {
        // 保证两个堆的元素个数满足：n_large = n_small || n_large = n_small + 1
        if(n % 2) { // 奇数，加入到较小堆
            // 先加入较大堆，再将较大堆的最小值加入到较小堆，保证较大堆的元素全都大于较小堆
            large.push(num);
            small.push(large.top());
            large.pop();
        } else { // 偶数，加入到较大堆
            small.push(num);
            large.push(small.top());
            small.pop();
        }
        n++;
    }
    
    double findMedian() {
        double res = 0;
        if (n % 2) // 奇数，取较大堆的最小值
            res = large.top();
        else // 偶数，两个堆的大小相等，取 较大堆的最小值 与 较小堆的最大值 的平均值
            res = (large.top() + small.top()) / 2.0;
        
        return res;
    }
};

/**
 * https://leetcode-cn.com/problems/find-median-from-data-stream/
 * https://mp.weixin.qq.com/s/oklQN_xjYy--_fbFkd9wMg 
 * 
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */