/*
 * @lc app=leetcode.cn id=1232 lang=cpp
 *
 * [1232] 缀点成线
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coord) {
        int n = coord.size();
        if (n < 3) return true;

        for (int i = 2; i < n; i++) {
             if ((coord[i][0] - coord[i-1][0]) * (coord[i-1][1] - coord[i-2][1]) !=
             (coord[i-1][0] - coord[i-2][0]) * (coord[i][1] - coord[i-1][1]))

                return false;
        }

        return true;
    }
};
// @lc code=end

