#include "../utils/abel_macro.h"

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ans = 0;
        unordered_map<char,int> right;
        for (int i = 0; i < garbage.size(); i++) {
            ans += garbage[i].length();
            for (char c : garbage[i]) {
                right[c] = i;
            }
        }
        for (const auto& pair : right) {
            ans += accumulate(travel.begin(), travel.begin() + pair.second, 0);
        }
        return ans;
    }
};