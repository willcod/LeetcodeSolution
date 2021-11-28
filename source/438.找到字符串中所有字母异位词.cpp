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

    vector sv(26, 0);
    vector pv(26, 0);

    for (int i = 0; i < p.length(); i++) {
      sv[s[i] - 'a']++;
      pv[p[i] - 'a']++;
    }

    vector res(0, 0);

    if (sv == pv) res.push_back(0);

    for (int i = p.length(); i < s.length(); i++) {
      sv[s[i] - 'a']++;
      sv[s[i - p.length()] - 'a']--;

      if (sv == pv) res.push_back(i - p.length() + 1);
    }

    return res;
  }
};
// @lc code=end
