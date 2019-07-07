#pragma once
#include <vector>
#include <string>

struct Solution
{
    std::string s;
    int n;

    bool check(int mid, std::vector<int>& res)
    {
        int counta = 0;
        int countb = 0;
        for (auto i = 0; i < n; i++) {
            if (s[i] == '(') {
                if (counta < mid) {
                    counta++;
                    res[i] = 1;
                } else {
                    if (countb == mid)
                        return false;
                    countb++;
                    res[i] = 0;
                }
            } else {
                if (counta) {
                    counta--;
                    res[i] = 1;
                } else {
                    if (!countb)
                        return false;
                    countb--;
                    res[i] = 0;
                }
            }
        }
        return true;
    }

    std::vector<int> maxDepthAfterSplit(std::string seq)
    {
        s = seq;
        n = seq.size();
        std::vector<int> res(n);
        auto l = 1;
        auto r = n / 2;
        while (l + 1 < r) {
            auto mid = (l + r) / 2;
            if (check(mid, res))
                r = mid;
            else
                l = mid;
        }
        if (check(l, res))
            r = l;
        check(r, res);
        return res;
    }
};

