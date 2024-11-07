#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxCnt = 0;
        for (const int& k : numSet) {
            if (!numSet.contains(k-1)) {
                int curCnt = 1, k1 = k;
                while (numSet.contains(k1 + 1)) {
                    ++curCnt;
                    ++k1;
                }
                maxCnt = max(maxCnt, curCnt);
            }
        }
        return maxCnt;
    }
};

int main() {
    Solution a;
    vector<int> nums({100, 4, 200, 1, 3, 2});
    cout << a.longestConsecutive(nums) << endl;
    nums.assign({0,3,7,2,5,8,4,6,0,1});
    cout << a.longestConsecutive(nums) << endl;
}