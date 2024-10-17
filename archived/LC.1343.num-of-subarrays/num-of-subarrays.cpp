#include "abel_macro.h"

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int cnt = 0;
        double sum = 0.0;
        for (int i=0; i<arr.size(); ++i) {
            sum += arr[i];
            if (i < k-1) continue;
            if (sum >= threshold * k) cnt++;
            sum -= arr[i-k+1];
        }
        return cnt;
    }
};