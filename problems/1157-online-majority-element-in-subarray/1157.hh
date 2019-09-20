#include <algorithm>
#include <vector>
#include <random>
#include <iterator>

auto constexpr tries = 20;

struct MajorityChecker
{
    std::vector<std::vector<int>> pos;
    std::vector<int> a;
    int n;

    MajorityChecker(std::vector<int>& arr)
        : pos(20001), a(arr), n(a.size())
    {
        for (auto i = 0; i < n; i++)
            pos[a[i]].emplace_back(i);
    }

    int get_count(int x, int l, int r)
    {
        auto lower = std::lower_bound(pos[x].begin(), pos[x].end(), l);
        auto upper = std::upper_bound(pos[x].begin(), pos[x].end(), r);
        upper = std::prev(upper);
        return upper - lower + 1;
    }

    int query(int left, int right, int threshold)
    {
        std::random_device rd{};
        std::mt19937 gen{rd()};
        std::uniform_int_distribution<> dis(left, right);
        for (auto i = 0; i < tries; i++) {
            auto guess = dis(gen);
            auto count = get_count(a[guess], left, right);
            if (2 * count > right - left + 1) {
                if (count < threshold)
                    return -1;
                else
                    return a[guess];
            }
        }
        return -1;
    }
};

