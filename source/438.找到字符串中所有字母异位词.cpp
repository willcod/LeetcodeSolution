/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    vector<int> findAnagrams(string s, string p) {
        if (s.length() < p.length()) return {};

        vector<int> pv(26, 0);
        vector<int> sv(26, 0);

        vector<int> res;

        for (int i = 0; i < p.size(); i++) {
            pv[p[i] - 'a']++;
            sv[s[i] - 'a']++;
        }

        if (pv == sv) res.push_back(0);

        for (int i = p.size(); i < s.size(); i++) {
            sv[s[i] - 'a']++;
            sv[s[i - p.size()] - 'a']--;

            if (sv == pv) res.push_back(i - p.size() + 1);
        }

        return res;
    }
};
// @lc code=end
