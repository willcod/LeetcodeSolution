/*
 * @lc app=leetcode.cn id=1024 lang=cpp
 *
 * [1024] 视频拼接
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:

// Sort clips first.
// Then for each clip, update dp[clip[0]] ~ dp[clip[1]].

// Time O(NlogN + NT), Space O(T)
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(), clips.end());
        vector f(101, 101);
        f[0] = 0;
        for (auto c : clips) {
            for (int i = c[0] + 1; i <= c[1]; i++) {
                f[i] = min(f[i], f[c[0]] + 1);
            }
        }

        return f[T] >= 100 ? -1 : f[T];
    }
};
// @lc code=end

