struct Solution
{
    bool isPowerOfThree(int n)
    {
        if (n <= 0)
            return false;
        auto s = 1;
        for (auto i = 0; i < 19; i++, s *= 3)
            if (s == n)
                return true;
        return s == n;
    }
};

