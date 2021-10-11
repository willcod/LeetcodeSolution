/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
    string keyboard[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string str;

        if (digits.length() == 0) return {};

        letterCombinations(res, str, digits, 0);
        return res;
    }

    void letterCombinations(vector<string>&res, string str, string digits, int index) {
        if (str.length() == digits.length()) {
            res.push_back(str);
            return;
        }

        string keys = keyboard[digits[index]-'0'];
        for (int i = 0; i < keys.length(); i++) {
            letterCombinations(res, str+keys[i], digits, index+1);
        }
    }
};
// @lc code=end

