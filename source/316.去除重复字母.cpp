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
        string result = "";

        for (auto c : s) counter[c]++;

        for (auto c : s) {
            counter[c]--;
            if (visited[c]) continue;

            while (!result.empty() && c < result.back() &&
                   counter[result.back()] > 0) {
                visited[result.back()] = false;
                result.pop_back();
            }

            result += c;
            visited[c] = true;
        }

        return result;
    }
};
// @lc code=end
