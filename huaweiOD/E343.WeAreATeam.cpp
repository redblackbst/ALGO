#include <iostream>
#include <vector>
using namespace std;

int findRoot(int x, vector<int>& parent) {
    if (parent[x] != x) {
        parent[x] = findRoot(parent[x], parent);
    }
    return parent[x];
}