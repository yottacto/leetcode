#include <set>
#include <vector>
#include <stack>
#include <iterator>
#include <algorithm>

struct DinnerPlates
{
    std::set<int> not_full;
    std::set<int> not_empty;
    std::vector<std::stack<int>> da;
    int c;

    DinnerPlates(int capacity)
        : c(capacity)
    {
    }

    void push(int val)
    {
        if (not_full.empty()) {
            da.emplace_back();
            da.back().emplace(val);
            not_empty.emplace(da.size() - 1);
            if (c > 1)
                not_full.emplace(da.size() - 1);
        } else {
            auto choose = *not_full.begin();
            da[choose].emplace(val);
            if ((int)da[choose].size() == 1)
                not_empty.emplace(choose);
            if ((int)da[choose].size() == c)
                not_full.erase(not_full.begin());
        }
    }

    int pop()
    {
        if (not_empty.empty())
            return -1;
        auto choose = *std::prev(std::end(not_empty));
        auto top = da[choose].top();
        if ((int)da[choose].size() == c)
            not_full.emplace(choose);
        if (da[choose].size() == 1)
            not_empty.erase(std::prev(std::end(not_empty)));
        da[choose].pop();
        return top;
    }

    int popAtStack(int choose)
    {
        if (da[choose].empty())
            return -1;
        auto top = da[choose].top();
        if ((int)da[choose].size() == c)
            not_full.emplace(choose);
        if (da[choose].size() == 1)
            not_empty.erase(std::prev(std::end(not_empty)));
        da[choose].pop();
        return top;
    }
};

