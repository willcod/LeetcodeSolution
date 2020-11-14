/*
 * @lc app=leetcode.cn id=1002 lang=cpp
 *
 * [1002] 查找常用字符
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> res;

        vector minCnt(26, INT_MAX);

        for (auto s : A) {
            vector cnt(26, 0);
            for (auto c : s) {
                cnt[c - 'a']++;
            }

            for (int i = 0; i < 26; i++) {
                minCnt[i] = min(minCnt[i], cnt[i]);
            }
        }

        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < minCnt[i]; j++) {
                res.push_back(string(1, i + 'a'));
            }
        }

        return res;
    }
};
// @lc code=end
