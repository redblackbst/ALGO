#include "../utils/abel_macro.h"

class BookMyShow {
    int n, m;
    vector<int> mn;
    vector<long long> sum;

    void update(int o, int l, int r, int i, int val) {
        if (l == r) {
            mn[o] += val;
            sum[o] += val;
            return;
        }
        int m = (l + r) / 2;
        if (i <= m) {
            update(o * 2, l, m, i, val);
        } else {
            update(o * 2 + 1, m + 1, r, i, val);
        }
        mn[o] = min(mn[o*2], mn[o*2+1]);
        sum[o] = sum[o*2] + sum[o*2+1];
    }

    long long querySum(int o, int l, int r, int L, int R) {
        if (L <= l && r <= R) {
            return sum[o];
        }
        long long res = 0;
        int m = (l + r) / 2;
        if (L <= m) {
            res = querySum(o * 2, l, m, L, R);
        }
        if (m < R) {
            res += querySum(o * 2 + 1, m + 1, r, L, R);
        }
        return res;
    }

    int findFirst(int o, int l, int r, int R, int val) {
        if (mn[o] > val) {
            return -1;
        }
        if (l == r) {
            return l;
        }
        int m = (l + r) / 2;
        if (mn[o*2] <= val) {
            return findFirst(o * 2, l, m, R, val);
        }
        if (m < R) {
            return findFirst(o * 2 + 1, m + 1, r, R, val);
        }
        return -1;
    }

public:
    BookMyShow(int n, int m) : n(n), m(m), mn(2 << (32 - __builtin_clz(n))), sum(2 << (32 - __builtin_clz(n))) {}

    vector<int> gather(int k, int maxRow) {
        int r = findFirst(1, 0, n - 1, maxRow, m - k);
        if (r < 0) {
            return {};
        }
        int c = querySum(1, 0, n - 1, r, r);
        update(1, 0, n - 1, r, k);
        return {r, c};
    }
    
    bool scatter(int k, int maxRow) {
        long long s = querySum(1, 0, n - 1, 0, maxRow);
        if (s > (long long) m * (maxRow + 1) - k) {
            return false;
        }
        int i = findFirst(1, 0, n - 1, maxRow, m - 1);  // < m
        while (k) {
            int left = min(m - (int) querySum(1, 0, n - 1, i, i), k);
            update(1, 0, n - 1, i, left);
            k -= left;
            i++;
        }
        return true;
    }
};

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */