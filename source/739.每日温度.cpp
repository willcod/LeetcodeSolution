/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector ans(n, 0);
        stack<int> stk;

        for (int i = 0; i < n; i++) {
            while (stk.size() && T[stk.top()] < T[i]) {
                int cur = stk.top();
                stk.pop();
                ans[cur] = i - cur;
            }

            stk.push(i);
        }

        return ans;
    }
};
// @lc code=end
