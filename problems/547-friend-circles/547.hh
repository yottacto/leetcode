#include <vector>
#include <numeric>

struct Solution
{
    std::vector<int> parent;
    int tot;

    int get_parent(int x)
    {
        return x == parent[x]
            ? x
            : parent[x] = get_parent(parent[x]);
    }

    void set_union(int x, int y)
    {
        auto tx = get_parent(x);
        auto ty = get_parent(y);
        if (tx != ty) {
            parent[tx] = ty;
            tot--;
        }
    }

    int findCircleNum(std::vector<std::vector<int>>& m)
    {
        int n = m.size();
        tot = n;
        parent.resize(n);
        std::iota(parent.begin(), parent.end(), 0);
        for (auto i = 0; i < n; i++)
            for (auto j = i + 1; j < n; j++)
                if (m[i][j])
                    set_union(i, j);
        return tot;
    }
};

