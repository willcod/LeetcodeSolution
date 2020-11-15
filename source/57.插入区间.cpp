/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& inter, vector<int>& newInter) {
        vector<vector<int>> res;
        int n = inter.size();
        int i = 0;
        while (i < n && inter[i][1] < newInter[0]) res.push_back(inter[i++]);

        while (i < n && inter[i][0] <= newInter[1]) {
            newInter[0] = min(inter[i][0], newInter[0]);
            newInter[1] = max(inter[i][1], newInter[1]);
            i++;
        }

        res.push_back(newInter);

        while (i < n && inter[i][0] > newInter[1]) res.push_back(inter[i++]);

        return res;
    }
};
// @lc code=end

