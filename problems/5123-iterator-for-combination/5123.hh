#include <bits/stdc++.h>

struct CombinationIterator
{
    std::string s;
    int len;
    int n;
    int state;

    CombinationIterator(std::string characters, int combinationLength)
        : s(characters), len(s.size()), n(combinationLength), state((1<<(len - n)) - 1)
    {
    }

    uint32_t next(uint32_t v)
    {
        uint32_t t = v | (v - 1);
        return (t + 1) | (((~t & -~t) - 1) >> (__builtin_ctz(v) + 1));
    }

    std::string next()
    {
        std::string res;
        auto ts = ((1<<len) - 1) ^ state;
        for (auto i = len - 1; i >= 0; i--)
            if (ts & (1<<i))
                res += s[len - i - 1];
        state = next(state);
        return res;
    }

    bool hasNext() const
    {
        return state < (1<<len);
    }
};

