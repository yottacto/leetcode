#pragma once
#include <unordered_map>
#include <set>

struct data
{
    int count;
    int id;
    int value;
};

auto operator<(data const& a, data const& b)
{
    return a.count > b.count
        || (a.count == b.count && a.id > b.id);
}

struct FreqStack
{
    std::unordered_map<int, int> count;
    std::unordered_map<int, int> last;
    std::unordered_map<int, int> prev;
    std::set<data> datas;
    int alloc{0};

    FreqStack() { }

    void push(int x)
    {
        alloc++;
        if (count[x]) {
            datas.erase(data{count[x], last[x], x});
            prev[alloc] = last[x];
        }
        last[x] = alloc;
        count[x]++;
        datas.insert(data{count[x], alloc, x});
    }

    int pop()
    {
        auto top = *datas.begin();
        datas.erase(datas.begin());
        count[top.value]--;
        if (count[top.value]) {
            last[top.value] = prev[top.id];
            datas.insert(data{top.count-1, prev[top.id], top.value});
        }
        return top.value;
    }
};

