#include "abel_macro.h"

class Solution {
public:
    int beautifulBouquet(vector<int>& flowers, int cnt) {
        long long ans = 0;
        unordered_map<int,int> freq;
        for (int i=0, j=0; j<flowers.size(); ++j) {
            freq[flowers[j]]++;
            while (freq[flowers[j]] > cnt) {
                freq[flowers[i]]--;
                ++i;
            }
            ans += j-i+1;
        }
        return ans % int(1e9+7);
    }
};