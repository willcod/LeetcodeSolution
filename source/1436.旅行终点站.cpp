/*
 * @lc app=leetcode.cn id=1436 lang=cpp
 *
 * [1436] 旅行终点站
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> startCities;
        unordered_set<string> endCities;

        for (int i = 0; i < paths.size(); i++) {
            startCities.insert(paths[i][0]);
            endCities.insert(paths[i][1]);
        }

        for (auto dest : endCities) {
            if (!startCities.count(dest)){
                return dest;
            }
        }

        return "";
    }
};
// @lc code=end

