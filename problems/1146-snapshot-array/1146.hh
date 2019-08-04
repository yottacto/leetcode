#include <vector>
#include <map>
#include <iterator>

struct SnapshotArray
{
    std::vector<int> version;
    std::vector<std::map<int, int>> values;
    int cur_id;

    SnapshotArray(int length)
        : version(length), values(length), cur_id(0)
    {
        for (auto& v : values)
            v[cur_id] = 0;
    }

    void set(int index, int val)
    {
        if (version[index] != cur_id) {
            values[index][cur_id] = val;
            version[index] = cur_id;
        } else {
            values[index].rbegin()->second = val;
        }
    }

    int snap()
    {
        return ++cur_id;
    }

    int get(int index, int snap_id)
    {
        return std::prev(values[index].upper_bound(snap_id))->second;
    }
};

