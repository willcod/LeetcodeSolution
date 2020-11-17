/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    vector<int> partitionLabels(string S) {
        vector<int> pos(26, 0);
        for (int i = 0; i < S.length(); i++) {
            pos[S[i] - 'a'] = i;
        }

        vector<int> parts;

        int start = 0;
        int end = 0;
        for (int i = 0; i < S.length(); i++) {
            end = max(end, pos[S[i] - 'a']);
            if (end == i) {
                parts.push_back(end - start + 1);
                start = end + 1;
            }
        }

        return parts;
    }
};
// @lc code=end
