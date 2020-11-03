/*
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    unordered_map<string, vector<string>> m;

    vector<string> help(string s, vector<string>& wordDict) {
        if (s.empty()) return {""};

        if (m.find(s) != m.end()) return m[s];

        vector<string> subpart, wholepart;
        for (string word : wordDict) {
            string igot = s.substr(0, word.length());

            if (igot != word) {
                continue;
            } else {
                subpart = help(s.substr(word.length()), wordDict);
            }

            for (string ans : subpart) {
                string space = ans.length() == 0 ? "" : " ";
                wholepart.push_back(word + space + ans);
            }
        }

        return m[s] = wholepart;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        m.clear();
        return help(s, wordDict);
    }
};
// @lc code=end
