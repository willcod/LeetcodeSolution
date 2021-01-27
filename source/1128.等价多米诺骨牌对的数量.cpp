/*
 * @lc app=leetcode.cn id=1128 lang=cpp
 *
 * [1128] 等价多米诺骨牌对的数量
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector count(100, 0);

        int res = 0;
        for (auto& d : dominoes) {
            auto key = d[0] > d[1] ? d[0] * 10 + d[1] : d[1] * 10 + d[0];
            res += count[key];
            count[key]++;
        }
        return res;
    }
};
// @lc code=end
