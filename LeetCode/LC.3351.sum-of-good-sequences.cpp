#include "../utils/abel_macro.h"

class Solution {
public:
    // 特殊子序列 DP
    // 简单版本：怎么求个数？
    // 遍历数组的同时，“维护”以 x 结尾的子序列的元素和/个数，以子序列的倒数第二个数转移过来
    // x = nums[i]
    // cnt[x] = cnt[x] + cnt[x-1] + cnt[x+1] + 1
    // f[x] 表示以元素 x 结尾的子序列的元素之和
    // f[x] = f[x] + (f[x-1] + cnt[x-1]*x) + (f[x+1] + cnt[x+1]*x) + x
    int sumOfGoodSubsequences(vector<int>& nums) {
        int MOD = 1'000'000'007;
        unordered_map<int, int> f, cnt;
        for (int x : nums) {
            long long c = cnt[x-1] + cnt[x+1] + 1;
            f[x] = (x * c + f[x] + f[x-1] + f[x+1]) % MOD;
            cnt[x] = (cnt[x] + c) % MOD;
        }
        long long ans = 0;
        for (const auto& [_, s] : f) {
            ans += s;
        }
        return ans % MOD;
    }
};