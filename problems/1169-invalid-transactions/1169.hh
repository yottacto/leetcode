#include <vector>
#include <string>
#include <sstream>
#include <cmath>

struct _data
{
    std::string s;
    std::string name;
    int t;
    int amount;
    std::string city;

};

struct Solution
{
    bool inrange(int t0, int t1, int d = 60)
    {
        return std::abs(t0 - t1) <= d;
    }

    std::vector<std::string> invalidTransactions(std::vector<std::string>& transactions)
    {
        std::vector<_data> da;
        for (auto const& t : transactions) {
            _data tmp;
            auto i0 = t.find(",", 0);
            auto i1 = t.find(",", i0 + 1);
            auto i2 = t.find(",", i1 + 1);
            tmp.name = t.substr(0, i0);
            tmp.t = std::stoi(t.substr(i0 + 1, i1 - i0 - 1));
            tmp.amount = std::stoi(t.substr(i1 + 1, i2 - i1 - 1));
            tmp.city = t.substr(i2 + 1);
            tmp.s = t;
            da.emplace_back(tmp);
        }
        std::vector<std::string> res;
        int n = da.size();
        for (auto i = 0; i < n; i++) {
            auto valid = [&](int i) {
                if (da[i].amount > 1000)
                    return false;
                for (auto j = 0; j < n; j++) {
                    if (i == j)
                        continue;
                    if (da[i].name == da[j].name && inrange(da[i].t, da[j].t) && da[i].city != da[j].city)
                        return false;
                }
                return true;
            };
            if (!valid(i))
                res.emplace_back(da[i].s);
        }
        return res;
    }
};

