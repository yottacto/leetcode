struct Solution
{
    using ll = long long;

    int mySqrt(int x)
    {
        if (!x)
            return 0;
        int l = 1;
        int r = x;
        while (l + 1 < r) {
            auto mid = l + (r - l) / 2;
            if (mid <= x / mid)
                l = mid;
            else
                r = mid;
        }
        if (r <= x / r)
            l = r;
        return l;
    }
};

