/*
 * @lc app=leetcode.cn id=983 lang=cpp
 *
 * [983] 最低票价
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.back();
        vector f(n + 1, 0);

        int d = 0;
        for (int i = 1; i <= n; i++) {
            if (i != days[d]) {
                f[i] = f[i - 1];
            } else {
                f[i] = min({f[max(0, i - 1)] + costs[0],
                            f[max(0, i - 7)] + costs[1],
                            f[max(0, i - 30)] + costs[2]});
                d++;
            }
        }

        return f[n];
    }
};
// @lc code=end
