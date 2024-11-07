#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0] * nums[0];
        vector<long long> aPre(n), aSuf(n), bPre(n), bSuf(n);
        aPre[0] = bPre[0] = nums[0];
        aSuf[n-1] = bSuf[n-1] = nums[n-1];
        for (int i = 1; i < n; ++i) {
            aPre[i] = gcd(aPre[i-1], nums[i]);
            // bPre[i] = bPre[i-1] * nums[i] / aPre[i];
            bPre[i] = lcm(bPre[i-1], nums[i]);
            int j = n - i - 1;
            aSuf[j] = gcd(aSuf[j+1], nums[j]);
            // bSuf[j] = bSuf[j+1] * nums[i] / aSuf[j];
            bSuf[j] = lcm(bSuf[j+1], nums[j]);
        }
        long long maxSc = aPre[n-1] * bPre[n-1];
        for (int i = 0; i < n; ++i) {
            long long aCur, bCur;
            if (i == 0) {
                aCur = aSuf[1];
                bCur = bSuf[1];
            } else if (i == n-1) {
                aCur = aPre[n-2];
                bCur = bPre[n-2];
            } else {
                aCur = gcd(aPre[i-1], aSuf[i+1]);
                // bCur = bPre[i-1] * bSuf[i+1] / aCur;
                bCur = lcm(bPre[i-1], bSuf[i+1]);
            }
            maxSc = max(maxSc, aCur * bCur);
        }
        cout << maxSc << endl;
        return maxSc;
    }
};

int main() {
    Solution a;
    // vector<int> nums{2,4,8,16};
    // vector<int> nums{1,2,3,4,5};
    vector<int> nums{3};
    a.maxScore(nums);
}