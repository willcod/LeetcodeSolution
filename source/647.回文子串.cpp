/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; i-j >= 0 && s[i-j] == s[i+j]; j++) count++;
            for (int j = 0; i-j-1 >= 0 && s[i-1-j] == s[i+j];j++) count++;
        }
        return count;
    }
};
// @lc code=end

