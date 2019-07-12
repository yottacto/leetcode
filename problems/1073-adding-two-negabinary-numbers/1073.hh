#pragma once

struct Solution
{
    std::vector<int> addNegabinary(std::vector<int>& arr1, std::vector<int>& arr2)
    {
        std::reverse(arr1.begin(), arr1.end());
        std::reverse(arr2.begin(), arr2.end());
        int l1 = arr1.size();
        int l2 = arr2.size();
        int l = std::max(l1, l2);
        while (l1 < l) {
            arr1.emplace_back(0);
            l1++;
        }
        while (l2 < l) {
            arr2.emplace_back(0);
            l2++;
        }
        std::vector<int> res;
        for (auto i = 0; i < l; i++) {
            int r = arr1[i] + arr2[i];
            if (r == -1) {
                r = 1;
                if (i == l - 1) {
                    arr1.emplace_back(0);
                    arr2.emplace_back(0);
                    l++;
                }
                arr1[i + 1] += 1;
            } else if (r >= 2) {
                r %= 2;
                if (i == l - 1) {
                    arr1.emplace_back(0);
                    arr2.emplace_back(0);
                    l++;
                }
                arr1[i + 1] -= 1;
            }
            res.emplace_back(r);
        }
        while (res.size() != 1 && res.back() == 0)
            res.pop_back();
        std::reverse(res.begin(), res.end());
        return res;
    }
};

