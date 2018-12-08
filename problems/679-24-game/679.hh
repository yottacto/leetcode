#pragma once
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <set>
#include <functional>
#include <numeric>
#include <iterator>
#include <cmath>

auto constexpr eps = 1e-7;

// +, -, *, /
struct Solution
{
    std::vector<double> nums;
    std::vector<int> op_id;
    std::unordered_map<int, std::function<double(double, double)>> op{
        {0, std::plus<double>{}},
        {1, std::minus<double>{}},
        {2, std::multiplies<double>{}},
        {3, std::divides<double>{}},
    };

    auto dfs(std::vector<double> const& a, std::vector<int> const& op_id)
    {
        int n = a.size();
        std::set<double> res;
        if (n == 1) {
            res.insert(a[0]);
            return res;
        }
        for (auto i = 0; i < n - 1; i++) {
            // division by zero
            if (op_id[i] == 3 && !a[i+1])
                continue;
            auto x = op[op_id[i]](a[i], a[i+1]);
            auto ta = a;
            ta[i+1] = x;
            ta.erase(ta.begin() + i);
            auto top_id = op_id;
            top_id.erase(top_id.begin() + i);
            auto dfs_res = dfs(ta, top_id);
            res.insert(dfs_res.begin(), dfs_res.end());
        }
        return res;
    }

    auto equal(std::set<double> const& s, double v = 24) -> bool
    {
        auto it = s.lower_bound(v);
        if (it != s.end()) {
            if (std::fabs(*it - v) <= eps)
                return true;
        }
        it = s.upper_bound(v);
        if (it != s.begin()) {
            if (std::fabs(*std::prev(it) - v) <= eps)
                return true;
        }
        return s.count(v);
    }

    auto check(int st) -> bool
    {
        for (auto i = 0; i < 3; i++) {
            op_id[i] = st % 4;
            st /= 4;
        }
        auto res = dfs(nums, op_id);
        return equal(res);
    }

    bool judgePoint24(std::vector<int> const& nums)
    {
        int n = nums.size();
        this->nums.resize(n);
        op_id.resize(n - 1);
        std::vector<int> pos(n);
        std::iota(pos.begin(), pos.end(), 0);
        do {
            for (auto i = 0; i < n; i++)
                this->nums[i] = nums[pos[i]];
            for (auto i = 0; i < (1<<6); i++)
                if (check(i)) return true;
        } while (std::next_permutation(pos.begin(), pos.end()));
        return false;
    }
};

