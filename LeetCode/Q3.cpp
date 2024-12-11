#include "../utils/abel_macro.h"

#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
public:
    int n;
    vector<int> tree, lazy;

    SegmentTree(vector<int>& nums) : n(nums.size()), tree(4*n), lazy(4*n) {
        build(nums, 1, 0, n - 1);
    }

    void build(vector<int>& nums, int c, int l, int r) {
        if (l == r) {
            tree[c] = nums[l];
            return;
        }
        int mid = (l + r) / 2;
        build(nums, 2 * c, l, mid);
        build(nums, 2 * c + 1, mid + 1, r);
        tree[c] = max(tree[2*c], tree[2*c+1]);
    }

    void push(int c, int l, int r) {
        if (lazy[c] != 0) {
            tree[c] -= lazy[c];
            if (l != r) {
                lazy[2*c] += lazy[c];
                lazy[2*c + 1] += lazy[c];
            }
            lazy[c] = 0;
        }
    }

    void update(int c, int l, int r, int ql, int qr, int val) {
        push(c, l, r);
        if (ql > r || qr < l)
            return;
        if (ql <= l && r <= qr) {
            lazy[c] += val;
            push(c, l, r);
            return;
        }
        int mid = (l + r) / 2;
        update(2 * c, l, mid, ql, qr, val);
        update(2 * c + 1, mid + 1, r, ql, qr, val);
        tree[c] = max(tree[2*c], tree[2*c+1]);
    }

    int queryMax() {
        push(1, 0, n - 1);
        return tree[1];
    }
};

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        SegmentTree st(nums);
        if (st.queryMax() == 0) return 0;
        int k = 0;
        for (auto& q : queries) {
            k++;
            int l = q[0], r = q[1], v = q[2];
            st.update(1, 0, st.n - 1, l, r, v);
            if (st.queryMax() <= 0) return k;
        }
        return -1;
    }
};

int main() {
    Solution a;
    vector<int> nums{2,0,2};
    vector<vector<int>> queries{{0,2,1},{0,2,1},{1,1,3}};
    cout << a.minZeroArray(nums, queries) << endl;
}