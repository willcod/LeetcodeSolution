/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    bool isValid(string s) {
        stack<char> stk;
        for (auto c : s) {
            if (c == '(' || c == '[' || c == '{') {
                stk.push(c);
            } else {
                if (stk.empty()) return false;
                if (c == ')' && stk.top() != '(') return false;
                if (c == ']' && stk.top() != '[') return false;
                if (c == '}' && stk.top() != '{') return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};
// @lc code=end
