#include "../utils/abel_macro.h"

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegrees(numCourses);
        vector<vector<int>> adjacency(numCourses);
        for (auto e : prerequisites) {
            indegrees[e[0]]++;
            adjacency[e[1]].push_back(e[0]);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (!indegrees[i]) q.push(i);
        }
        while (!q.empty()) {
            int pre = q.front();
            q.pop();
            numCourses--;
            for (int cur : adjacency[pre]) {
                indegrees[cur]--;
                if (!indegrees[cur]) {
                    q.push(cur);
                }
            }
        }
        return numCourses == 0;
    }
};