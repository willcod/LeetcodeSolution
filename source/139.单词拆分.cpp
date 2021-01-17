/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict({wordDict.begin(), wordDict.end()});
        int n = s.length();
        vector f(n + 1, false);
        f[0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                f[i] = f[j] && (dict.count(s.substr(j, i - j)));

                if (f[i]) break;
            }
        }

        return f[n];
    }
};
// @lc code=end
