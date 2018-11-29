#pragma once
#include <algorithm>
#include <iterator>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <utility>
#include <numeric>

struct top10
{
    using value_type = std::pair<int, int>;
    std::set<value_type> data;

    void insert(value_type const& d)
    {
        data.insert(d);
    }
};

top10 operator+(top10 const& lhs, top10 const& rhs)
{
    top10 dest;
    std::set_union(
        lhs.data.begin(), lhs.data.end(),
        rhs.data.begin(), rhs.data.end(),
        std::inserter(dest.data, dest.data.begin())
    );
    return dest;
}

struct Twitter
{
    int index{0};
    std::unordered_map<int, top10> users;
    std::unordered_map<int, std::unordered_set<int>> follows;


    /** Initialize your data structure here. */
    Twitter()
    {
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId)
    {
        users[userId].insert({index--, tweetId});
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    std::vector<int> getNewsFeed(int userId)
    {
        if (!users.count(userId))
            return {};
        auto const& user = follows[userId];
        auto all = std::accumulate(user.begin(), user.end(), users[userId], [this](top10 const& lhs, int followeeId) {
            return lhs + users[followeeId];
        });
        auto last = all.data.end();
        if (all.data.size() > 10)
            last = std::next(all.data.begin(), 10);
        std::vector<int> res;
        for (auto it = all.data.begin(); it != last; ++it)
            res.emplace_back(it->second);
        return res;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId)
    {
        if (!users.count(followerId))
            users[followerId];
        follows[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId)
    {
        if (!follows.count(followerId) || !follows[followerId].count(followeeId))
            return;
        follows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * std::vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */

