#include <vector>

struct Solution
{
    void fill(std::vector<char>& chars, int& len, int count)
    {
        int n = 0;
        for (auto tc = count; tc; tc /= 10)
            n++;
        for (auto i = 0; i < n; i++, count /= 10)
            chars[len + n - i - 1] = '0' + (count % 10);
        len += n;
    }

    int compress(std::vector<char>& chars)
    {
        int n = chars.size();
        auto j = 0;
        auto len = 0;
        auto count = 0;
        for (auto i = 0; i < n; i++) {
            if (chars[i] == chars[j])
                count++;
            if (i == n - 1 || chars[i] != chars[i + 1]) {
                chars[len++] = chars[j];
                if (count > 1)
                    fill(chars, len, count);
                j = i + 1;
                count = 0;
            }
        }
        return len;
    }
};

