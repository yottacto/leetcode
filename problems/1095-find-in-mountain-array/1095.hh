#pragma once

// // This is the MountainArray's API interface.
// // You should not implement it, or speculate about its implementation
// struct MountainArray
// {
//     int get(int index);
//     int length();
// };

struct Solution
{
    int find_left(int target, int l, int r, MountainArray& ma)
    {
        while (l <= r) {
            auto mid = (l + r) / 2;
            int a = ma.get(mid);
            if (target == a) {
                return mid;
            } else if (target < a) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }

    int find_right(int target, int l, int r, MountainArray& ma)
    {
        while (l <= r) {
            auto mid = (l + r) / 2;
            int a = ma.get(mid);
            if (target == a) {
                return mid;
            } else if (target < a) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return -1;
    }

    int find_max(MountainArray& ma)
    {
        int l = 0;
        int r = ma.length() - 1;
        while (l + 1 < r) {
            auto mid = (l + r) / 2;
            int a = ma.get(mid - 1);
            int b = ma.get(mid);
            int c = ma.get(mid + 1);
            if (a < b && b < c) {
                l = mid + 1;
            } else if (a < b && b > c) {
                return mid;
            } else {
                r = mid - 1;
            }
        }
        if (ma.get(l) > ma.get(r))
            return l;
        else
            return r;
    }

    int findInMountainArray(int target, MountainArray& ma)
    {
        auto max = find_max(ma);
        auto l = find_left(target, 0, max, ma);
        if (l != -1)
            return l;
        return find_right(target, max, ma.length() - 1, ma);
    }
};

