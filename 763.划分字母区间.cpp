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
        vector<int> res;
        int n = S.length();
        if (n < 2) return {n};

        unordered_map<char, int> pos;
        for (int i = 0; i < n; i++) {
            pos[S[i]] = i;
        }

        int start = 0;
        int end = 0;
        for (int i = 0; i < n; i++) {
            end = max(end, pos[S[i]]);
            if (end == i) {
                res.emplace_back(end - start + 1);
                start = i + 1;
            }
        }

        return res;
    }
};
// @lc code=end

