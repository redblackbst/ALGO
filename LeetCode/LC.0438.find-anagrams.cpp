#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> map, window;
        for (char c : p) map[c]++;
        int left = 0, right = 0, valid = 0;
        vector<int> res;
        while (right < s.size()) {
            char c = s[right];
            right++;
            if (map.contains(c)) {
                window[c]++;
                if (window[c] == map[c]) {
                    valid++;
                }
            }
            while (right - left >= p.size()) {
                if (valid == map.size()) {
                    res.push_back(left);
                }
                char d = s[left];
                left++;
                if (map.contains(d)) {
                    if (map[d] == window[d]) {
                        valid--;
                    }
                    window[d]--;
                }
            }
        }
        return res;
    }
};