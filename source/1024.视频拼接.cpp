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
        if (clips.empty()) return -1;

        sort(clips.begin(), clips.end());

        int count = 0;
        int end = 0;
        int st = 0;

        while (st < T) {
            for (int i = 0; i < clips.size(); i++) {
                if (clips[i][0] <= st) {
                    end = max(end, clips[i][1]);
                }
            }
            if (st == end) return -1;
            st = end;
            count++;
        }

        return count;
    }
};
// @lc code=end
