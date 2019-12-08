struct Solution
{
    int subtractProductAndSum(int n)
    {
        auto sum = 0;
        auto prod = 1;
        for (; n; n /= 10) {
            auto tn = n % 10;
            sum += tn;
            prod *= tn;
        }
        return prod - sum;
    }
};

