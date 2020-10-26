/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
  public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);
        int length = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i);
                } else {
                    length = max(length, i - stk.top());
                }
            }
        }

        return length;
    }
};
// @lc code=end
