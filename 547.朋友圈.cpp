/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 朋友圈
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        vector visited(n, false);

        int circleNum = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                circleNum++;
                visit(M, i, visited);
            }
        }

        return circleNum;
    }

    void visit(vector<vector<int>>& M, int i, vector<bool>& visited) {
        if (visited[i] == false) {
            visited[i] = true;
            for (int j = 0; j < M.size(); j++) {
                if (M[i][j] == 1 && !visited[j]) {
                    visit(M, j, visited);
                }
            }
        }
    }
};
// @lc code=end
