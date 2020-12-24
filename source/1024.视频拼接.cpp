/*
 * @lc app=leetcode.cn id=1024 lang=cpp
 *
 * [1024] 视频拼接
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        int n = clips.size();
        if (n == 1) return T >= clips[0][0] && T <= clips[0][1];

        sort(clips.begin(), clips.end());

        vector f(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < n; j++) {
                if (clips[j][0] <= f[i - 1]) {
                    f[i] = max(f[i], clips[j][1]);
                }

                if (f[i] >= T) return i;
            }
        }
        return -1;
    }
};
// @lc code=end
