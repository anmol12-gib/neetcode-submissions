class Twitter {
public:

    int timer = 0;

    unordered_map<int, unordered_set<int>> Follow;
    unordered_map<int, vector<pair<int, int>>> tweets;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        
        priority_queue<pair<int, int>> pq;

        // Own tweets
        for(auto it : tweets[userId]) {
            pq.push(it);
        }

        // Tweets of followed users
        for(int person : Follow[userId]) {
            for(auto it : tweets[person]) {
                pq.push(it);
            }
        }

        vector<int> ans;

        while(!pq.empty() && ans.size() < 10) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId)
            Follow[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        Follow[followerId].erase(followeeId);
    }
};