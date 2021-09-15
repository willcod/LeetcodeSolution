/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int countSubstrings(string s) {
        int res = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            for (int j = 0; i -j >= 0 && i+j <n&& s[i-j] == s[i+j]; j++) res++;
            for (int j = 0; i-j-1>=0 && i+j <n && s[i-j-1] == s[i+j];j++) res++;
        }
        return res;
    }
};
// @lc code=end
