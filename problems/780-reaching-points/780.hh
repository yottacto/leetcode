struct Solution
{
    bool reachingPoints(int sx, int sy, int tx, int ty)
    {
        while ((tx != sx || ty != sy) && tx && ty) {
            if (tx > ty) {
                if (ty == sy)
                    return (tx >= sx) && ((tx - sx) % ty == 0);
                else
                    tx %= ty;
            } else {
                if (tx == sx)
                    return (ty >= sy) && ((ty - sy) % tx == 0);
                else
                    ty %= tx;
            }
        }
        return tx == sx && ty == sy;
    }
};

