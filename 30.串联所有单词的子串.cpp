/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.empty()) return res;
        int n = s.size();
        int m = words.size();
        int w = words[0].size();
        unordered_map<string, int> hashCount;
        for (auto word : words) {
            hashCount[word]++;
        }

        for (int i = 0; i < w; i++) {
            int suc = 0;
            unordered_map<string, int> window;
            for (int j = i; j + w <= n; j += w) {
                if (j >= i + m * w) {
                    string cur = s.substr(j - m * w, w);
                    window[cur]--;
                    if (window[cur] < hashCount[cur]) suc--;
                }
                string cur = s.substr(j, w);
                window[cur]++;
                if (window[cur] <= hashCount[cur]) suc++;
                if (suc == m) res.push_back(j - (m - 1) * w);
            }
        }
        return res;
    }
};
// @lc code=end
