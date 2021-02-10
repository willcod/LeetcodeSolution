/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;

        partition(res, path, s, 0);
        return res;
    }

    void partition(vector<vector<string>>&res, vector<string>& path, string&s, int index) {
        if (index == s.length()) {
            res.push_back(path);
            return;
        }

        for (int i = index; i < s.length(); i++) {
            if (!isPalindrome(s, index, i)) continue;

            path.push_back(s.substr(index, i-index+1));
            partition(res, path, s, i+1);
            path.pop_back();
        }
    }

    bool isPalindrome(string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
};
// @lc code=end
