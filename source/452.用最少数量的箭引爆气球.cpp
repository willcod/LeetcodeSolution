/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());

        int n = points.size();

        for (int i = 1; i < points.size(); i++) {
            if (points[i-1][1] >= points[i][0]) {
                n--;
                points[i][1] = min(points[i][1], points[i-1][1]);
            } 
        }

        return n;
    }
};
// @lc code=end

