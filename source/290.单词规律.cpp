/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> c2s;
        unordered_map<string, char> s2c;
        stringstream ss(s);
        string str;

        for (auto c : pattern) {
            if (!(ss >> str) || (c2s.count(c) && c2s[c] != str) || (s2c.count(str) && s2c[str] != c))
                return false;
            else {
                c2s[c] = str;
                s2c[str] = c;
            }
        }
        return ss >> str ? false : true;
    }
};
// @lc code=end

