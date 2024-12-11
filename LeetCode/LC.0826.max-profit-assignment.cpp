#include "../utils/abel_macro.h"

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        vector<pair<int, int>> jobs(n);
        for (int i = 0; i < n; i++) {
            jobs[i] = {difficulty[i], profit[i]};
        }
        ranges::sort(jobs);
        ranges::sort(worker);
        int ans = 0, j = 0, maxProfit = 0;
        for (int w : worker) {
            while (j < n && jobs[j].first <= w) {
                maxProfit = max(maxProfit, jobs[j].second);
                j++;
            }
            ans += maxProfit;
        }
        return ans;
    }
};