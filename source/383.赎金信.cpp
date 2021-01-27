/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> remain(128, 0);
        for (char c : magazine) {
            remain[c]++;
        }

        for (char c : ransomNote) {
            if (--remain[c] < 0) {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end

