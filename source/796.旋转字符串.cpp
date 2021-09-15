/*
 * @lc app=leetcode.cn id=796 lang=cpp
 *
 * [796] 旋转字符串
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    bool rotateString(string A, string B) {
        if (A.length() != B.length()) return false;
        if (A == B) return true;

        return (A + A).find(B) != string::npos;
    }
};
// @lc code=end
