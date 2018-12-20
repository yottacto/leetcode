#pragma once
#include <algorithm>
#include <numeric>
#include <vector>
#include <set>

auto constexpr inf = 1<<30;

struct Solution
{
    int n;
    int m;

    int calc(std::vector<int>& v, int k)
    {
        int n = v.size();
        std::partial_sum(v.begin(), v.end(), v.begin());
        std::set<int> s;
        s.insert(0);
        auto res = -inf;
        for (auto i = 0; i < n; i++) {
            auto si = v[i];
            auto sj = s.lower_bound(si - k);
            if (sj != s.end())
                res = std::max(res, si - *sj);
            s.insert(si);
        }
        return res;
    }

    void trans(std::vector<std::vector<int>>& matrix, int& n, int& m)
    {
        std::swap(n, m);
        auto mat = matrix;
        matrix.clear();
        matrix.resize(n, std::vector<int>(m));
        for (auto i = 0; i < n; i++)
            for (auto j = 0; j < m; j++)
                matrix[i][j] = mat[j][i];
    }

    int maxSumSubmatrix(std::vector<std::vector<int>>& matrix, int k)
    {
        n = matrix.size();
        m = matrix[0].size();
        if (n > m) trans(matrix, n, m);
        auto sum = matrix;
        for (auto i = 1; i < n; i++)
            for (auto j = 0; j < m; j++)
                sum[i][j] += sum[i - 1][j];
        auto res = -inf;
        for (auto i = 0; i < n; i++)
            for (auto j = i; j < n; j++) {
                std::vector<int> v(m);
                for (auto k = 0; k < m; k++)
                    v[k] = sum[j][k] - (i ? sum[i - 1][k] : 0);
                res = std::max(res, calc(v, k));
            }
        return res;
    }
};

