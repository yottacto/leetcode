using ll = long long;

auto constexpr mo = 1000000007ll;

struct Solution
{
    int countVowelPermutation(int n)
    {
        ll f[n][5];
        for (auto i = 0; i < 5; i++)
            f[0][i] = 1;
        for (auto i = 1; i < n; i++) {
            f[i][0] = (f[i - 1][1] + f[i - 1][2] + f[i - 1][4]) % mo;
            f[i][1] = (f[i - 1][0] + f[i - 1][2]) % mo;
            f[i][2] = (f[i - 1][1] + f[i - 1][3]) % mo;
            f[i][3] = (f[i - 1][2]) % mo;
            f[i][4] = (f[i - 1][2] + f[i - 1][3]) % mo;
        }
        ll res{0};
        for (auto i = 0; i < 5; i++)
            res = (res + f[n - 1][i]) % mo;
        return res;
    }
};

