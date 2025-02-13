#include "../utils/abel_macro.h"

class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> score;
        for (string& s : operations) {
            if (s == "+") {
                int k = score.size();
                score.push_back(score[k-2] + score[k-1]);
            } else if (s == "C") {
                score.pop_back();
            } else if (s == "D") {
                score.push_back(score.back() * 2);
            } else {
                score.push_back(stoi(s));
            }
        }
        return accumulate(score.begin(), score.end(), 0);
    }
};