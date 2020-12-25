/*
 * @lc app=leetcode.cn id=1021 lang=cpp
 *
 * [1021] 删除最外层的括号
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    string removeOuterParentheses(string S) {
        int open = 0;
        string res;

        for (char c : S) {
            if (c == '(' && open++ > 0) res += c;
            if (c == ')' && open-- > 1) res += c;
        }

        return res;
    }
};
// @lc code=end
