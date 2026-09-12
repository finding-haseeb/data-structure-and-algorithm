class Twitter {
public:
    int timer;
    unordered_map<int,vector<pair<int,int>>> tweets;
    unordered_map<int,unordered_set<int>> following;

    Twitter() {
        timer=0;
    }

    void postTweet(int userId,int tweetId) {
        tweets[userId].push_back({timer++,tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<pair<int,int>> feed;

        for(auto it:tweets[userId]) {
            feed.push_back(it);
        }

        for(int user:following[userId]) {
            for(auto it:tweets[user]) {
                feed.push_back(it);
            }
        }

        sort(feed.rbegin(),feed.rend());

        vector<int> ans;
        for(int i=0;i<min(10,(int)feed.size());i++) {
            ans.push_back(feed[i].second);
        }

        return ans;
    }

    void follow(int followerId,int followeeId) {
        if(followerId!=followeeId) {
            following[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId,int followeeId) {
        following[followerId].erase(followeeId);
    }
};