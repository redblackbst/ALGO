#include "../utils/abel_macro.h"

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0, right = n + 1; // (0, n+1) or [1, n]
        while (left + 1 < right) {
            // invariant: left=>yes, right=>no
            int mid = left + (right - left) / 2;
            // most cited papers have citations >= mid
            if (citations[n-mid] >= mid) {
                left = mid;
            } else {
                right = mid;
            }
        }
        // according to the invariant, left is the largest s.t. answer is yes
        return left;
    }
};

int main() {
    Solution a;
    // vector<int> cit{0,1,3,5,6};
    vector<int> cit{1,2,100};
    cout << a.hIndex(cit) << endl;
}