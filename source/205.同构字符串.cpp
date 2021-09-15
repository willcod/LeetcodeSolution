/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();

        for (int i = 0; i < n; i++) {
            if (s.find(s[i]) != t.find(t[i])) return false;
        }

        return true;
    }
};
// @lc code=end
