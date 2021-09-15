/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    string removeDuplicates(string S) {
        string res;

        for (int i = 0; i < S.length(); i++) {
            if (res.empty()) {
                res.push_back(S[i]);
            } else {
                if (res.back() == S[i]) {
                    res.pop_back();
                } else {
                    res.push_back(S[i]);
                }
            }
        }
        return res;
    }
};
// @lc code=end
