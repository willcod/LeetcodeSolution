/*
 * @lc app=leetcode.cn id=1190 lang=cpp
 *
 * [1190] 反转每对括号间的子串
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    string reverseParentheses(string s) {
        string res;
        stack<string> stk;
        for (char c : s) {
            if (c == '(') {
                stk.push(res);
                res = "";
            } else if (c == ')') {
                reverse(res.begin(), res.end());
                res = stk.top() + res;
                stk.pop();
            } else {
                res.push_back(c);
            }
        }
        return res;
    }
};
// @lc code=end
