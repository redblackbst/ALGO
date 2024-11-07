#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0, right = 0, n = nums.size();
        while (right < n) {
            if (nums[right]) {
                swap(nums[left], nums[right]);
                ++left;
            }
            ++right;
        }
    }
};

int main() {
    Solution a;
    vector<int> nums({0,1,0,3,12});
    a.moveZeroes(nums);
    for (auto x : nums) {
        cout << x << " ";
    }
}