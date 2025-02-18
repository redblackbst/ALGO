#include "../utils/abel_macro.h"

class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string,int> cnt;
        for (int i = 0; i < senders.size(); i++) {
            cnt[senders[i]] += 1 + ranges::count_if(messages[i], [](unsigned char c){ return isspace(c); });
        }
        return ranges::max_element(cnt, [](const auto& a, const auto& b) {
            return a.second < b.second || (a.second == b.second && a.first < b.first);
        })->first;
    }
};