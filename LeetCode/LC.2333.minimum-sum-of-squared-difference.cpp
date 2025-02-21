#include "../utils/abel_macro.h"

class Solution {
public:
    long long minSumSquareDiff(vector<int>& a, vector<int>& nums2, int k1, int k2) {
        int k = k1 + k2;
        long long ans = 0;
        int n = a.size();
        for (int i = 0; i < n; i++) {
            a[i] = abs(a[i] - nums2[i]);
            ans += (long long) a[i] * a[i];
        }
        if (reduce(a.begin(), a.end(), 0LL) <= k) {
            return 0;
        }
        ranges::sort(a, ranges::greater());
        a.push_back(0); // to avoid index oob
        for (int i = 0; i < n; i++) {
            long long v = a[i];
            ans -= v * v;
            int c = i + 1;
            long long cnt = c * (v - a[i+1]);
            if (cnt < k) {
                k -= cnt;
                continue;
            }
            v -= (int) k / c;
            ans += (k % c) * (v - 1) * (v - 1);
            ans += (c - k % c) * v * v;
            break;
        }
        return ans;
    }
};