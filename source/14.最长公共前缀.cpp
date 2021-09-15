/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) return strs[0];

        string s = "";
        for (int i = 0; i < strs[0].size(); i++) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].size() || strs[j][i] != c) return s;
            }

            s += c;
        }

        return s;
    }
};
// @lc code=end
