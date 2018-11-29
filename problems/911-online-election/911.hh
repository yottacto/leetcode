#pragma once
#include <vector>
#include <set>
#include <map>

struct state
{
    state(int id) : id(id), count(0), time(0) {}

    void add(int time)
    {
        count++;
        this->time = time;
    }

    int id;
    int count;
    int time;
};

auto operator<(state const& lhs, state const& rhs)
{
    return lhs.count > rhs.count
        || (lhs.count == rhs.count && lhs.time > rhs.time);
}

struct TopVotedCandidate
{
    std::set<state> pool;
    std::map<int, state> all;
    std::vector<int> leader;
    std::vector<int> times;

    TopVotedCandidate(std::vector<int> persons, std::vector<int> times)
        : times(times)
    {
        int n = persons.size();
        for (auto i = 0; i < n; i++) {
            pool.emplace(i);
            all.emplace(i, i);
        }
        leader.reserve(n);
        for (auto i = 0; i < n; i++) {
            auto p = persons[i];
            auto t = times[i];
            pool.erase(all.at(p));
            all.at(p).add(t);
            pool.insert(all.at(p));
            leader.emplace_back(pool.begin()->id);
        }
    }

    int q(int t)
    {
        auto p = std::upper_bound(times.begin(), times.end(), t) - times.begin() - 1;
        return leader[p];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */

