/*
 * @lc app=leetcode.cn id=301 lang=cpp
 *
 * [301] 删除无效的括号
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int l = 0, r = 0;
        for (auto c : s) {
            if (c == '(') l++;
            else if (c == ')') {
                if (l <= 0) r++;
                else l--;
            }
        }

        dfs(s, 0, "", 0, l, r);

        vector<string> res{ans.begin(), ans.end()};
        return res;
    }

    void dfs(string s, int index, string res, int count, int l, int r) {
        if (index == s.length()) {
            if (!count) ans.insert(res);
            return;
        }

        if (s[index] == '(') {
            dfs(s, index+1, res+'(', count+1, l, r);
            if (l > 0) dfs(s, index+1, res, count, l-1, r);
        } else if (s[index] == ')') {
            if (count > 0) dfs(s, index+1, res+')', count-1, l, r);
            if (r > 0) dfs(s, index+1, res, count, l, r-1);
        } else {
            dfs(s, index+1, res+s[index], count, l, r);
        }
    }

    private:
    unordered_set<string> ans;
};
// @lc code=end

