#pragma once
#include <iostream>
#include <vector>
#include <string>

class Solution
{
    using ll = long long;
public:

    ll parse(std::string ip)
    {
        auto s = ip.substr(0, ip.find("."));
        ip.erase(0, ip.find(".") + 1);
        ll ret = std::stoi(s);

        s = ip.substr(0, ip.find("."));
        ip.erase(0, ip.find(".") + 1);
        ret = (ret << 8) + std::stoi(s);

        s = ip.substr(0, ip.find("."));
        ip.erase(0, ip.find(".") + 1);
        ret = (ret << 8) + std::stoi(s);

        ret = (ret << 8) + std::stoi(ip);
        return ret;
    }

    std::string parse_back(ll now, int zero)
    {
        now <<= zero;
        std::string ret;
        for (int i = 0; i < 4; i++) {
            auto tmp = now % 256;
            auto pre = std::to_string(tmp);
            if (i != 0) pre += ".";
            ret = pre + ret;
        }
        return ret;
    }

    std::string calc(ll now, ll re, int& i)
    {
        int fix = 32;
        while (1 << (32 - fix) <= re) {
            if (now & 1) break;
            now /= 2;
        }
        i += 1 << (32 - fix);
        auto ret = parse_back(now, 32 - fix);
        ret += "/" + std::to_string(fix);
        return ret;
    }

    std::vector<std::string> ipToCIDR(std::string ip, ll range)
    {
        auto now = parse(ip);
        std::vector<std::string> ans;
        for (int i = 0; i < range; i++) {
            ans.emplace_back(calc(now, range - i, i));
        }
        return ans;
    }
};

