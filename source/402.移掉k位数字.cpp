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
        int n = num.length();
        int remain = n - k;

        string res = "";
        for (char c : num) {
            while (res.length() && res.back() > c && k) {
                res.pop_back();
                k--;
            }
            res.push_back(c);
        }

        res.resize(remain);
        int pos = res.find_first_not_of('0');
        if (pos == string::npos) return "0";
        return res.substr(pos);
    }
};
// @lc code=end
