/*
 * @lc app=leetcode.cn id=767 lang=cpp
 *
 * [767] 重构字符串
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    string reorganizeString(string S) {
        unordered_map<char, int> hash;
        int maxCount = 0;
        for (char c : S) {
            hash[c]++;
            maxCount = max(maxCount, hash[c]);
        }

        if (maxCount > (S.length() + 1) / 2) return "";

        vector<pair<char, int>> vec(hash.begin(), hash.end());
        sort(vec.begin(), vec.end(),
             [](const pair<char, int>& a, const pair<char, int>& b) {
                 return a.second > b.second;
             });

        string res(S);
        int index = 0;
        for (int i = 0; i < vec.size(); i++) {
            while (vec[i].second--) {
                res[index] = vec[i].first;
                index += 2;

                if (index >= S.length()) {
                    index = 1;
                }
            }
        }

        return res;
    }
};
// @lc code=end
