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
        unordered_map<char, int> remain;
        unordered_map<char, bool> visited;

        for (char c : s) {
            remain[c]++;
            visited[c] = false;
        }

        string str = "";
        for (char c : s) {
            remain[c]--;
            if (visited[c]) continue;

            while (str.size() && str.back() > c && remain[str.back()] > 0) {
                visited[str.back()] = false;
                str.pop_back();
            }

            str.push_back(c);
            visited[c] = true;
        }

        return str;
    }
};
// @lc code=end
