/*
 * @lc app=leetcode.cn id=402 lang=cpp
 *
 * [402] 移掉K位数字
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";

        int remain = num.size() - k;

        for (char c : num) {
            while (ans.size() && ans.back() > c && k) {
                ans.pop_back();
                k--;
            }

            ans.push_back(c);
        }

        ans.resize(remain);
        int pos = ans.find_first_not_of('0');
        if (pos == string::npos) return "0";
        return ans.substr(pos);
    }
};
// @lc code=end

