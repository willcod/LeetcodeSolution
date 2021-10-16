/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:
    string keyboard[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string str;

        if (digits.empty()) return res;

        letterCombinations(res, str, digits, 0);
        return res;
    }

    void letterCombinations(vector<string>&res, string str, string digits, int index) {
        if (str.length() == digits.length()) {
            res.push_back(str);
            return;
        }

        string keys = keyboard[digits[index] - '0'];
        for (char c : keys) {
            letterCombinations(res, str+c, digits, index+1);
        }
    }
};
// @lc code=end

