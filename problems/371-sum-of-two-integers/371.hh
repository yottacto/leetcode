struct Solution
{
    int getSum(int a, int b)
    {
        return !b ? a : getSum(a ^ b, (a & b) << 1);
    }
};

