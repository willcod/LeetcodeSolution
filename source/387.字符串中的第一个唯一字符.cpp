/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int firstUniqChar(string s) {
        vector<int> counter(128, 0);

        for (int i = 0; i < s.length(); i++) {
            counter[s[i]]++;
        }

        for (int i = 0; i < s.length(); i++) {
            if (counter[s[i]] == 1) return i;
        }

        return -1;
    }
};
// @lc code=end
