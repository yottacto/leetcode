#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

auto constexpr inf = 1<<30;

struct Solution
{
    int n;
    int m;

    std::vector<std::vector<int>> f;
    std::vector<std::vector<std::pair<int, int>>> jump;

    std::vector<int> smallestSufficientTeam(std::vector<std::string>& req_skills, std::vector<std::vector<std::string>>& people)
    {
        std::unordered_map<std::string, int> skills;
        n = people.size();
        m = req_skills.size();
        for (auto i = 0; i < m; i++) {
            skills[req_skills[i]] = i;
        }
        std::vector<int> a;
        a.reserve(n);
        for (auto const& s : people) {
            auto st = 0;
            for (auto const& i : s) {
                if (skills.count(i))
                    st |= 1 << skills[i];
            }
            a.emplace_back(st);
        }

        // for (auto i : a)
        //     std::cout << i << " ";
        // std::cout << "\n";

        f.resize(n + 1, std::vector<int>(1<<m, inf));
        jump.resize(n + 1, std::vector<std::pair<int, int>>(1<<m));

        f[0][0] = 0;
        for (auto i = 1; i <= n; i++) {
            f[i] = f[i - 1];
            auto cur = a[i - 1];
            for (auto j = 0; j < (1<<m); j++) {
                jump[i][j] = std::make_pair(0, j);
                if ((cur & j) != cur || f[i - 1][j ^ cur] == inf)
                    continue;
                if (f[i][j] > f[i - 1][j ^ cur] + 1) {
                    f[i][j] = f[i - 1][j ^ cur] + 1;
                    jump[i][j] = std::make_pair(1, j ^ cur);
                }
            }
            for (auto j = (1<<m) - 1; j >= 0; j--) {
                for (auto k = 0; k < m; k++) {
                    if (!(j & (1<<k)))
                        continue;
                    if (f[i][j] < f[i][j ^ (1<<k)]) {
                        f[i][j ^ (1<<k)] = f[i][j];
                        jump[i][j ^ (1<<k)] = std::make_pair(2, j);
                    }
                }
            }
        }

        // std::cout << f[1][1] << "\n";
        // std::cout << f[n][(1<<m) - 1] << "\n";

        std::vector<int> choose;
        auto j = (1<<m) - 1;
        for (auto i = n; i >= 0; i--) {
            while (jump[i][j].first == 2)
                j = jump[i][j].second;
            if (jump[i][j].first == 1) {
                choose.emplace_back(i - 1);
                j = jump[i][j].second;
            }
        }
        std::reverse(choose.begin(), choose.end());
        return choose;
    }
};

