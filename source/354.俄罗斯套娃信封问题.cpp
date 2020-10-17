/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.empty()) return 0;

        sort(envelopes.begin(), envelopes.end());
        vector f(envelopes.size(), 1);
        for (int i = 1; i < envelopes.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (envelopes[j][0] < envelopes[i][0] &&
                    envelopes[j][1] < envelopes[i][1])
                    f[i] = max(f[i], f[j] + 1);
            }
        }
        return *max_element(f.begin(), f.end());
    }
};
// @lc code=end
