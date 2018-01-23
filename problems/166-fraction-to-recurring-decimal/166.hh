#pragma once
#include <string>
#include <algorithm>

class Solution
{
    template <class T>
    T gcd(T a, T b) { return !b ? a : gcd(b, a % b); }

    template <class T>
    T abs(T x) { return x < 0 ? -x : x; }

    template <class T>
    T sign(T x) { return x < 0 ? -1 : 1; }

    template <int N, class T>
    auto get(T d) -> long long { return d % N ? 0 : 1 + get<N>(d / N); }

    template <int... N, class T>
    T pure(T d)
    {
        for (auto&& x : {N...})
            for (; d % x == 0; d /= x);
        return d;
    }

    int minimum_pow(int base, int mod)
    {
        auto p = base % mod;
        for (auto i = 1; ; i++, p = (p * base) % mod)
            if (p == 1)
                return i;
    }

public:
    std::string fractionToDecimal(long long numerator, long long denominator)
    {
        if (numerator == 0) return "0";
        auto tsign = sign(numerator) * sign(denominator);
        numerator = abs(numerator);
        denominator = abs(denominator);
        auto g = gcd(numerator, denominator);
        numerator /= g;
        denominator /= g;

        // integer
        auto res = std::to_string (numerator / denominator);
        if (tsign < 0) res = '-' + res;
        if (numerator % denominator == 0)
            return res;

        // decimal
        res += '.';
        auto transient = std::max(get<5>(denominator), get<2>(denominator));
        auto last = numerator %= denominator;
        for (auto i = 0; i < transient; i++) {
            last *= 10;
            res += std::to_string(last / denominator);
            last %= denominator;
        }
        auto a = pure<2, 5>(denominator);
        if (a == 1) return res;

        // repeating decimal
        auto repetend = minimum_pow(10, a);
        res += '(';
        for (auto i = 0; i < repetend; i++) {
            last *= 10;
            res += std::to_string(last / denominator);
            last %= denominator;
        }
        res += ')';
        return res;
    }
};

