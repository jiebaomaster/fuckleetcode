class Tweet {
public:
    int id = 0;
    Tweet *next = nullptr;
    int timestramp = 0;
    Tweet (int id, int timestramp, Tweet *next): id(id), timestramp(timestramp), next(next) {
    }
};

class User {
    int id = 0;
    Tweet *listhead = nullptr;
    unordered_set<int> follows;
    friend class Twitter;
public:
    User() {}

    void post(int tweetId, int timestramp) {
        Tweet *t = new Tweet(tweetId, timestramp, listhead);
        listhead = t;
    }
};

class Twitter {
    int timestramp = 0;
    unordered_map<int, User> userid_user;
public:
    /** Initialize your data structure here. */
    Twitter() {}
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        User &user = userid_user[userId];
        user.id = userId;
        user.post(tweetId, timestramp++);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        // 合并有序列表
        auto cmp = [](Tweet *l, Tweet *r) { return l->timestramp < r->timestramp; };
        priority_queue<Tweet *, vector<Tweet *>, decltype(cmp) > pq(cmp); // 定义使用特殊比较函数的优先级队列
        User &user = userid_user[userId];
        user.id = userId;
        user.follows.insert(userId); // 关注自己
        for(auto u : user.follows) { // 将所有关注用户的tweet列表头结点加入pq
            User &tmpuser = userid_user[u];
            if(tmpuser.listhead)
                pq.push(tmpuser.listhead);
        }
        vector<int> res;
        // 使用大顶堆，合并 n 个有序链表
        while(!pq.empty()) {
            auto it = pq.top(); // 大顶堆的头为最新的tweet
            res.push_back(it->id);
            if(res.size() == 10) // 最多10个
                break;
            pq.pop();
            if(it->next) // 出队的tweet如果其链表中还有下一个，继续入队
                pq.push(it->next);
        }

        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        User &follower = userid_user[followerId];
        follower.id = followerId;
        userid_user[followeeId].id = followeeId;
        follower.follows.insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        User &follower = userid_user[followerId];
        follower.id = followerId;
        userid_user[followeeId].id = followeeId;
        follower.follows.erase(followeeId);
    }
};

/**
 * https://leetcode-cn.com/problems/design-twitter/
 * https://labuladong.gitbook.io/algo/mu-lu-ye-1/mu-lu-ye-3/she-ji-twitter
 * 
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */