/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        stack<int> stk;
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            int sum = digits[i] + carry;

            stk.push(sum % 10);
            carry = sum / 10;
        }
        if (carry) stk.push(carry);

        while (stk.size()) {
            result.push_back(stk.top());
            stk.pop();
        }
        return result;
    }
};
// @lc code=end
