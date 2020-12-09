/*
 * @lc app=leetcode.cn id=1024 lang=cpp
 *
 * [1024] 视频拼接
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
  public:
    int videoStitching(vector<vector<int>> &clips, int T) {
        sort(clips.begin(), clips.end());

        int n = clips.size();
        vector fartest(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < n; j++) {
                if (clips[j][0] <= fartest[i - 1]) {
                    fartest[i] = max(fartest[i], clips[j][1]);
                }

                if (fartest[i] >= T)
                    return i;
            }
        }

        return -1;
    }
};
// @lc code=end
