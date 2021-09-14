/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> counter;
        unordered_map<char, bool> visited;

        for (auto c : s) {
            counter[c]++;
            visited[c] = false;
        }

        string res;
        for (auto c : s) {
            counter[c]--;
            if (visited[c]) continue;

            while (!res.empty() && res.back() > c && counter[res.back()] > 0) {
                visited[res.back()] = false;
                res.pop_back();
            }

            res.push_back(c);
            visited[res.back()] = true;
        }

        return res;
    }
};
// @lc code=end
