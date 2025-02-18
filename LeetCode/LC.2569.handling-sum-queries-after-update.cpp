#include "../utils/abel_macro.h"

class Solution {
    vector<int> cnt1, flip;

    void maintain(int o) {
        cnt1[o] = cnt1[o*2] + cnt1[o*2+1];
    }

    void do_(int o, int l, int r) {
        cnt1[o] = r - l + 1 - cnt1[o];
        flip[o] = !flip[o];
    }

    void build(vector<int>& a, int o, int l, int r) {
        if (l == r) {
            cnt1[o] = a[l];
            return;
        }
        int m = (l + r) / 2;
        build(a, o * 2, l, m);
        build(a, o * 2 + 1, m + 1, r);
        maintain(o);
    }

    void update(int o, int l, int r, int L, int R) {
        if (L <= l && r <= R) {
            do_(o, l, r);
            return;
        }
        int m = (l + r) / 2;
        if (flip[o]) {
            do_(o * 2, l, m);
            do_(o * 2 + 1, m + 1, r);
            flip[o] = false;
        }
        if (m >= L) {
            update(o * 2, l, m, L, R);
        }
        if (m < R) {
            update(o * 2 + 1, m + 1, r, L, R);
        }
        maintain(o);
    }

public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n = nums1.size();
        int m = 2 << (32 - __builtin_clz(n));
        cnt1.resize(m);
        flip.resize(m);
        build(nums1, 1, 0, n - 1);

        vector<long long> ans;
        long long sum = reduce(nums2.begin(), nums2.end(), 0LL);
        for (auto& q : queries) {
            if (q[0] == 1) {
                update(1, 0, n - 1, q[1], q[2]);
            } else if (q[0] == 2) {
                sum += (long long) q[1] * cnt1[1];
            } else {
                ans.push_back(sum);
            }
        }
        return ans;
    }
};