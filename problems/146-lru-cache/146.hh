#include <unordered_map>
#include <map>
#include <utility>

auto constexpr inf = 1<<30;

struct _data
{
    int key;
    int prev;
    int next;
};

struct LRUCache
{
    int id{};
    int capacity;
    std::unordered_map<int, std::pair<int, int>> values;
    std::unordered_map<int, _data> stamp;

    LRUCache(int capacity) : capacity(capacity)
    {
        stamp[-1] = _data{-1, -1, inf};
        stamp[inf] = _data{-1, -1, inf};
    }

    void erase(int t)
    {
        auto p = stamp[t].prev;
        auto n = stamp[t].next;
        stamp[p].next = n;
        stamp[n].prev = p;
        stamp.erase(t);
    }

    void insert_last(int key)
    {
        auto prev = stamp[inf].prev;
        stamp[id] = _data{key, prev, inf};
        stamp[prev].next = id;
        stamp[inf].prev = id;
        id++;
    }

    int get(int key)
    {
        if (!values.count(key))
            return -1;
        auto t = values.at(key).second;
        values.at(key).second = id;
        erase(t);
        insert_last(key);
        return values.at(key).first;
    }

    void put(int key, int value)
    {
        if (get(key) != -1) {
            values.at(key).first = value;
        } else {
            if (static_cast<int>(values.size()) == capacity) {
                auto nt = stamp[-1].next;
                auto key = stamp[nt].key;
                erase(nt);
                values.erase(key);
            }
            values[key] = {value, id};
            insert_last(key);
        }
    }
};

