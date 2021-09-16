/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mapping = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int result = 0;
        for (int i = 0; i < s.length(); i++) {
            int t = mapping[s[i]];
            if ((i+1 < s.length()) && t < mapping[s[i+1]]) {
                result -= t;
            } else {
                result += t;
            }
        }

        return result;
    }
};
// @lc code=end

