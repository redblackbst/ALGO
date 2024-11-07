#include "../utils/abel_macro.h"

int main() {
    int n, d;
    cin >> n >> d;
    vector<int> nums(n);
    for (int i  = 0; i < n; i++) {
        cin >> nums[i];
    }
    // 将队伍实力值从小到大排序
    sort(nums.begin(), nums.end());

    // dp[i]表示前i个队伍可以得到的最大匹配数
    vector<int> dp(n + 1, 0);
    // sum[i]表示匹配了dp[i]对时的最小实力差值总和
    vector<int> sum(n + 1, 0);

    for (int i = 2; i <= n; i++) {
        // 先假设不匹配第i个队伍，继承前一个状态
        dp[i] = dp[i - 1];
        sum[i] = sum[i - 1];

        // 如果第i个队伍和第i-1个队伍的实力差在允许范围内
        if (nums[i - 1] - nums[i - 2] <= d) {
            // 检查匹配当前这对是否能获得更多的匹配数
            if (dp[i - 2] + 1 > dp[i]) {
                dp[i] = dp[i - 2] + 1;
                sum[i] = sum[i - 2] + nums[i - 1] - nums[i - 2];
            } else if (dp[i - 2] + 1 == dp[i]) {
                // 如果匹配数相同，取实力差值总和较小的
                sum[i] = min(sum[i], sum[i - 2] + nums[i - 1] - nums[i - 2]);
            }
        }
    }

    if (dp[n] == 0) {
        cout << -1 << endl;
    } else {
        cout << sum[n] << endl;
    }

    return 0;
}