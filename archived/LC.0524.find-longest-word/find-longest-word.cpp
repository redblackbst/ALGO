#include "abel_macro.h"

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end(), [](string& a, string& b) {return a.size()>b.size() || a.size()== b.size() && a<b;});
        string ans = "";
        int maxlen = 0;
        for (string& word : dictionary) {
            int p = 0;
            for (char c : s) {
                if (word[p] == c) ++p;
                int n = word.size();
                if (p == n && maxlen < n) {
                    maxlen = n;
                    ans = word;
                };
            }
        }
        return ans;
    }
};