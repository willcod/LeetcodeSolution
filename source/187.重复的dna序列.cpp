/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> counters;
        vector<string> res;

        if (s.size() < 10) return res;

        for (int i = 0; i < s.size() - 9; i++) {
            counters[s.substr(i, 10)]++;
        }

        for (auto kv : counters) {
            if (kv.second > 1) {
                res.push_back(kv.first);
            }
        }

        return res;
    }
};
// @lc code=end

