class Twitter {
public:
    int timer;

    // user -> {time, tweetId}
    unordered_map<int, vector<pair<int,int>>> tweets;

    // user -> people they follow
    unordered_map<int, unordered_set<int>> followMap;

    Twitter() {
        timer = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {

        priority_queue<pair<int,int>> pq;

        // User should always follow himself
        followMap[userId].insert(userId);

        // Push all tweets of user and followees
        for (int person : followMap[userId]) {
            for (auto &tweet : tweets[person]) {
                pq.push({tweet.first, tweet.second});
            }
        }

        vector<int> ans;

        while (!pq.empty() && ans.size() < 10) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId)
            followMap[followerId].erase(followeeId);
    }
};  